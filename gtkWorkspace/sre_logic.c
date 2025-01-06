/*
 *  This file contains state logics functions.
 */
#include <gtk/gtk.h>
#include <stdio.h>

#include "headers/sre_can.h"
#include "headers/sre_logic.h"
#include "headers/debug_panel.h"
#include "headers/objects.h"

uint32_t displayCallbackCounter = 0;

SRE_State *sre_state;

char error_message[100];
char info_message[100];

void init_sre_state()
{
    printf("init_sre_state\n");
    sre_state = (SRE_State *)malloc(sizeof(SRE_State));
    if (sre_state == NULL)
    {
        printf("Failed to allocate memory for sre_state\n");
        return;
    }

    sre_state->brake_pressure_1 = 0;
    sre_state->brake_pressure_2 = 0;
    sre_state->asb_pressure_1 = 0;
    sre_state->asb_pressure_2 = 0;

    sre_state->sdc_power = 0;
    sre_state->lv_power = 0;
    sre_state->hv_power = 0;
    sre_state->epos_power = 0;

    sre_state->acu_switch = false;
    sre_state->asb_switch = false;
    sre_state->dash_switch = false;
    sre_state->epos_lc_switch = false;
    sre_state->fan_l_switch = false;
    sre_state->fan_r_switch = false;
    sre_state->sbg_switch = false;
    sre_state->vcu_switch = false;
    sre_state->pef_switch = false;
    sre_state->per_switch = false;
    sre_state->pumps_switch = false;
    sre_state->sensors_switch = false;

    sre_state->tsa_ready = false;
    sre_state->tsa_active = false;

    sre_state->r2d_ready = false;
    sre_state->r2d_active = false;

    sre_state->error_show = false;
    sre_state->info_show = false;

    sre_state->car_state = UNDEFINED_C;
    sre_state->bat_state = UNDEFINED_B;
    sre_state->asb_state = UNINITALIZED;
    sre_state->ami_state = MANUAL;
    sre_state->as_state = OFF;
    sre_state->sbs_state = DISENGAGED;
    sre_state->ebs_state = 0;
    sre_state->asb_check_sequence = 0;
    sre_state->asb_trigger_cause = 0;

    // printf("sre_state batstate: %s\n", BAT_STATE_STR[sre_state->bat_state]);
}

gboolean sre_run_display()
{
    displayCallbackCounter = ++displayCallbackCounter;
    if ((displayCallbackCounter % 10) == 0)
    {
        printf("sre_run_display, %d\n", displayCallbackCounter);
    }

    tsa_logic();
    r2d_logic();

    error_logic();
    info_logic();

    // Gathers all the data from the CAN messages and updates the states
    state_update();

    // Updates the graphical elements
    graphical_update();

    // Updates the labels
    label_update();

    return G_SOURCE_CONTINUE;
}

void state_update()
{
    // printf("state_update\n");

    sre_state->brake_pressure_1 = LOG_BrakePressures.Front;
    sre_state->brake_pressure_2 = LOG_BrakePressures.Rear;

    sre_state->asb_pressure_1 = DV_ASB_Pressure.Pressure1;
    sre_state->asb_pressure_2 = DV_ASB_Pressure.Pressure2;

    sre_state->sdc_power = 0; // Does not exist yet
    sre_state->lv_power = 0; // Does not exist yet
    sre_state->hv_power = GW_Battery_Status.Power;
    sre_state->epos_power =  0; // Does not exist yet

    // Switches do not exist yet

    sre_state->car_state = HSC_Vehicle_Status.State;
    sre_state->bat_state = GW_Battery_Status.State;
    sre_state->as_state = DV_System_Status.AS_State;
    sre_state->ami_state = DV_AMI_Status.State;
    sre_state->asb_state = DV_ASB_Status.State;
    sre_state->sbs_state = DV_ASB_Status.ServiceBrakeState;
    sre_state->ebs_state = DV_ASB_Status.EBS_State;
    sre_state->asb_checkup_complete = DV_ASB_Status.CheckupComplete;
    sre_state->asb_check_sequence = DV_ASB_Status.CheckSequence;
    sre_state->asb_trigger_cause = DV_ASB_Status.TriggerCause;
}

void label_update()
{
    // PRESSURES

    // printf("label_update\n");
    char buffer[100];
    sprintf(buffer, "%d", sre_state->brake_pressure_1);
    gtk_label_set_text(GTK_LABEL(label_brake_pressure_1), buffer);
    sprintf(buffer, "%d", sre_state->brake_pressure_2);
    gtk_label_set_text(GTK_LABEL(label_brake_pressure_2), buffer);

    sprintf(buffer, "%d", sre_state->asb_pressure_1);
    gtk_label_set_text(GTK_LABEL(label_asb_pressure_1), buffer);
    sprintf(buffer, "%d", sre_state->asb_pressure_2);
    gtk_label_set_text(GTK_LABEL(label_asb_pressure_2), buffer);

    // POWER MEASUREMENT
    sprintf(buffer, "%d", sre_state->sdc_power);
    gtk_label_set_text(GTK_LABEL(label_sdc_power), buffer);
    sprintf(buffer, "%d", sre_state->lv_power);
    gtk_label_set_text(GTK_LABEL(label_lv_power), buffer);
    sprintf(buffer, "%d", sre_state->hv_power);
    gtk_label_set_text(GTK_LABEL(label_hv_power), buffer);
    sprintf(buffer, "%d", sre_state->epos_power);
    gtk_label_set_text(GTK_LABEL(label_epos_power), buffer);



    // STATES
    sprintf(buffer, "%s", CAR_STATE_STR[sre_state->car_state]);
    gtk_label_set_text(GTK_LABEL(label_car_state), buffer);

    sprintf(buffer, "%s", BAT_STATE_STR[sre_state->bat_state]);
    gtk_label_set_text(GTK_LABEL(label_bat_state), buffer);

    sprintf(buffer, "%s", AS_STATE_STR[sre_state->as_state]);
    gtk_label_set_text(GTK_LABEL(label_as_state), buffer);

    sprintf(buffer, "%s", ASB_STATE_STR[sre_state->asb_state]);
    gtk_label_set_text(GTK_LABEL(label_asb_state), buffer);

    sprintf(buffer, "%d", sre_state->asb_check_sequence);
    gtk_label_set_text(GTK_LABEL(label_asb_check_sequence), buffer);

    sprintf(buffer, "%d", sre_state->asb_trigger_cause);
    gtk_label_set_text(GTK_LABEL(label_asb_trigger_cause), buffer);
}

void graphical_update()
{
    printf("graphical_update\n");

    // printf("car_state: %s\n", CAR_STATE_STR[sre_state->car_state]);
    // printf("bat_state: %s\n", BAT_STATE_STR[sre_state->bat_state]);

    if (sre_state->tsa_ready)
    {
        gtk_widget_add_css_class(GTK_WIDGET(label_tsa), "blink");
    }
    else
    {
        gtk_widget_remove_css_class(GTK_WIDGET(label_tsa), "blink");
    }

    if (sre_state->r2d_ready)
    {
        gtk_widget_add_css_class(GTK_WIDGET(label_r2d), "blink");
    }
    else
    {
        gtk_widget_remove_css_class(GTK_WIDGET(label_r2d), "blink");
    }

    if (sre_state->r2d_active)
    {
        gtk_widget_add_css_class(GTK_WIDGET(label_r2d), "active");
    }
    else
    {
        gtk_widget_remove_css_class(GTK_WIDGET(label_r2d), "active");
    }

    if (sre_state->tsa_active)
    {
        gtk_widget_add_css_class(GTK_WIDGET(label_tsa), "active");
    }
    else
    {
        gtk_widget_remove_css_class(GTK_WIDGET(label_tsa), "active");
    }

    printf("error_show: %d\n", sre_state->error_show);
    printf("info_show: %d\n", sre_state->info_show);
    gtk_widget_set_visible(GTK_WIDGET(box_error), sre_state->error_show);
    gtk_widget_set_visible(GTK_WIDGET(box_info), sre_state->info_show);
}

void tsa_logic()
{
    if (sre_state->car_state == WAIT_FOR_TSA_C && sre_state->bat_state == WAIT_FOR_TSA_B)
    {
        sre_state->tsa_ready = 1;
    }
    else
    {
        sre_state->tsa_ready = 0;
    }

    if (sre_state->bat_state == TSA)
    {
        sre_state->tsa_active = 1;
    }
    else
    {
        sre_state->tsa_active = 0;
    }
}

void r2d_logic()
{
    if (sre_state->car_state == WAIT_FOR_RTD && sre_state->bat_state == TSA)
    {
        sre_state->r2d_ready = 1;
    }
    else
    {
        sre_state->r2d_ready = 0;
    }

    if (sre_state->car_state == DRIVE)
    {
        sre_state->r2d_active = 1;
    }
    else
    {
        sre_state->r2d_active = 0;
    }
}

void error_logic()
{
    if(sre_state->car_state == SCS_ERROR)
    {
        sre_state->error_show = 1;

        // malloc the error struct
        SRE_error *scs_error = malloc(sizeof(SRE_error));
        if(scs_error != NULL)
        {
            strcpy(scs_error->error_type, CAR_STATE_STR[sre_state->car_state]);
            strcpy(scs_error->error_message, "");
        }
    }

    if(sre_state->bat_state == SDC_OPEN || sre_state->bat_state == ISO_ERROR 
    || sre_state->bat_state == BMS_ERROR || sre_state->bat_state == IMD_ERROR
    || sre_state->bat_state == BAT_ERROR)
    {
        sre_state->error_show = 1; //(sre_state->car_state >= RTD_OFF);

        // malloc the error struct
        SRE_error *bat_error = malloc(sizeof(SRE_error));
        if(bat_error != NULL)
        {
            strcpy(bat_error->error_type, BAT_STATE_STR[sre_state->bat_state]);
            strcpy(bat_error->error_message, "");
        }
    }

    if(sre_state->asb_state == EBS_TRIGGERED)
    {
        sre_state->error_show = 1;

        // malloc the error struct
        SRE_error *asb_error = malloc(sizeof(SRE_error));
        if(asb_error != NULL)
        {
            strcpy(asb_error->error_type, ASB_STATE_STR[sre_state->asb_state]);
            strcpy(asb_error->error_message, "");
        }
    }

    if((sre_state->asb_checkup_complete == 0) && (sre_state->asb_trigger_cause != 0))
    {
        sre_state->error_show = 1;

        // malloc the error struct
        SRE_error *asb_error = malloc(sizeof(SRE_error));
        if(asb_error != NULL)
        {
            strcpy(asb_error->error_type, ASB_TRIGGER_CAUSE_STR[sre_state->asb_trigger_cause]);
            strcpy(asb_error->error_message, "");
        }
    }

    if(SAF_AIN_F1_Status.data & 0x1F)
    {
        // malloc the error struct
        SRE_error *ain_error = malloc(sizeof(SRE_error));
        
        if(ain_error != NULL)
        {
            strcpy(ain_error->error_type, SAF_AIN_F1_Status_ERRORS_STR[get_bit_position(SAF_AIN_F1_Status.data)]);
            strcpy(ain_error->error_message, "");
        }
    }
}

void info_logic()
{

}

// returns the position of the first bit that is 1
uint32_t get_bit_position(uint32_t value) {
    for (int i = 0; i < 8; i++) {
        if (value & (1 << i)) {
            return i;
        }
    }
    return 0; // Return -1 if no bit is set
}