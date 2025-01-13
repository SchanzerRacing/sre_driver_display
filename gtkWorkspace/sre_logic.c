/*
 *  This file contains state logics functions.
 */
#include <gtk/gtk.h>
#include <stdio.h>
#include <time.h>

#include "headers/sre_can.h"
#include "headers/sre_logic.h"
#include "headers/debug_panel.h"
#include "headers/objects.h"

uint32_t displayCallbackCounter = 0;

SRE_State *sre_state;
SRE_error* vehicle_errors[MAX_ERRORS] = {NULL};

void init_sre_logic()
{
    // INITIALIZE SRE_STATE
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
    error_label_update();
    error_panel_update();

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

void error_label_update()
{
    uint8_t label_array_count = 0;

    for(int i = 0; i < ERROR_LABEL_COUNT; i++)
    {
        if(vehicle_errors[i] != NULL)
        {
            char buffer[100];
            // get error type string
            const char* error_type_str = ERROR_TYPES_STR[vehicle_errors[i]->error_type];

            // get sub error type string
            const char* sub_error_str = "N/A"; // default if no subtype exists
            if(vehicle_errors[i]->error_type < ERROR_TYPE_COUNT && 
                ERROR_SUB_TYPE_MAP[vehicle_errors[i]->error_type] != NULL &&
                vehicle_errors[i]->sub_error_type < ERROR_SUB_TYPE_COUNT) // avoid out of bounds
            {
                printf("error_type: %d, sub_error_type: %d\n", vehicle_errors[i]->error_type, vehicle_errors[i]->sub_error_type);
                sub_error_str = ERROR_SUB_TYPE_MAP[vehicle_errors[i]->error_type][vehicle_errors[i]->sub_error_type];
            }
            sprintf(buffer, "%s", error_type_str);
            gtk_label_set_text(GTK_LABEL(error_array[label_array_count][0]), buffer);
            sprintf(buffer, "%s", sub_error_str);
            gtk_label_set_text(GTK_LABEL(error_array[label_array_count][1]), buffer);

            label_array_count++;
        }
    }

    for(; label_array_count < ERROR_LABEL_COUNT; label_array_count++)
    {
        gtk_label_set_text(GTK_LABEL(error_array[label_array_count][0]), "");
        gtk_label_set_text(GTK_LABEL(error_array[label_array_count][1]), "");
    }
}

void error_panel_update()
{   
    uint8_t error_count = 0;
    for(int i = 0; i < MAX_ERRORS; i++)
    {
        if(vehicle_errors[i] != NULL)
        {
            error_count++;
        }
    }

    if(error_count > 0)
    {
        sre_state->error_show = 1;
    } else 
    {
        sre_state->error_show = 0;
    }

    if(sre_state->error_show)
    {
        gtk_widget_set_visible(GTK_WIDGET(box_error), true);
    } else 
    {
        gtk_widget_set_visible(GTK_WIDGET(box_error), false);
    }


    // @todo: add cycling error messages
    // cycle error messages
    if(error_count > 0)
    {
        // Find first error that is not NULL
        for(int i = 0; i < MAX_ERRORS; i++)
        {
            if(vehicle_errors[i] != NULL)
            {
                char buffer[100];
                const char* error_type_str = ERROR_TYPES_STR[vehicle_errors[i]->error_type];
                const char* sub_error_str = "N/A"; // default if no subtype exists
                if(vehicle_errors[i]->error_type < ERROR_TYPE_COUNT && 
                    ERROR_SUB_TYPE_MAP[vehicle_errors[i]->error_type] != NULL &&
                    vehicle_errors[i]->sub_error_type < ERROR_SUB_TYPE_COUNT) // avoid out of bounds
                {
                    sub_error_str = ERROR_SUB_TYPE_MAP[vehicle_errors[i]->error_type][vehicle_errors[i]->sub_error_type];
                }
                sprintf(buffer, "%s", error_type_str);
                gtk_label_set_text(GTK_LABEL(info_error_type), buffer);
                sprintf(buffer, "%s", sub_error_str);
                gtk_label_set_text(GTK_LABEL(info_error_message), buffer);
                break;
            }
        }
    } else 
    {
        gtk_label_set_text(GTK_LABEL(info_error_type), "");
        gtk_label_set_text(GTK_LABEL(info_error_message), "");
    }

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

    // printf("error_show: %d\n", sre_state->error_show);
    // printf("info_show: %d\n", sre_state->info_show);
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

/* --- VEHICLE ERROR MANAGMENT --- */

void error_logic()
{
    if(sre_state->car_state == SCS_ERROR)
    {
        SRE_error *buff_error = check_if_error_exists(VCU, VCU_SCS);
        if(buff_error == NULL)
        {
            printf("create buffer error, SCS_ERROR\n");
            SRE_error *new_buff_error = create_sre_error(VCU, VCU_SCS);
            add_error(new_buff_error);
        } else 
        {
            buff_error->last_seen = (uint64_t)time(NULL);
        }
    }

    if(sre_state->bat_state == SDC_OPEN || sre_state->bat_state == ISO_ERROR 
    || sre_state->bat_state == BMS_ERROR || sre_state->bat_state == IMD_ERROR
    || sre_state->bat_state == BAT_ERROR)
    {
        SRE_error *buff_error = check_if_error_exists(BAT_ERR, sre_state->bat_state);
        if(buff_error == NULL)
        {
            SRE_error *new_buff_error = create_sre_error(BAT_ERR, sre_state->bat_state);
            add_error(new_buff_error);
        } else 
        {
            buff_error->last_seen = (uint64_t)time(NULL);
        }
    }

    if(sre_state->asb_state == EBS_TRIGGERED && sre_state->asb_trigger_cause == 0)
    {
        SRE_error *buff_error = check_if_error_exists(ASB_ERROR, ASB_EBS_TRIGGERED);
        if(buff_error == NULL)
        {
            SRE_error *new_buff_error = create_sre_error(ASB_ERROR, ASB_EBS_TRIGGERED);
            add_error(new_buff_error);
        } else 
        {
            buff_error->last_seen = (uint64_t)time(NULL);
        }
    }

    if((sre_state->asb_state == EBS_TRIGGERED) && (sre_state->asb_trigger_cause != 0))
    {
        SRE_error *buff_error = check_if_error_exists(ASB_ERROR, sre_state->asb_trigger_cause);
        if(buff_error == NULL)
        {
            SRE_error *new_buff_error = create_sre_error(ASB_ERROR, sre_state->asb_trigger_cause);
            add_error(new_buff_error);
        } else 
        {
            buff_error->last_seen = (uint64_t)time(NULL);
        }
    }

    if(SAF_AIN_F1_Status.data & 0x1F)
    {
        // for(int i = 0; i < 5; i++)
        // {
        //     if(SAF_AIN_F1_Status.data & (1 << i))
        //     {
        //         SRE_error *buff_error = check_if_error_exists(SCS_ZOCO_FRONT, i);
        //         if(buff_error == NULL)
        //         {
        //             SRE_error *new_buff_error = create_sre_error(SCS_ZOCO_FRONT, i);
        //             add_error(new_buff_error);
        //         } else 
        //         {
        //             buff_error->last_seen = (uint64_t)time(NULL);
        //         }
        //     }
        // }
    }

    // Free old Error Messages
    for (int i = 0 ; i < MAX_ERRORS; i++)
    {
        if(vehicle_errors[i] != NULL)
        {
            if(vehicle_errors[i]->last_seen + FREE_AFTER <= (uint64_t)time(NULL))
            {
                remove_error(i);
            }
        }
    }
}

SRE_error* create_sre_error(uint16_t error_type, uint16_t sub_error_type)
{
    SRE_error* new_error = (SRE_error*)malloc(sizeof(SRE_error));
    if (!new_error) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }
    new_error->last_seen = (uint64_t)time(NULL);
    new_error->error_type = error_type;
    new_error->sub_error_type = sub_error_type;
    new_error->dismissed = 0;

    return new_error;
}

void add_error(SRE_error* error) {
    for (int i = 0; i < MAX_ERRORS; i++) {
        if (vehicle_errors[i] == NULL) {
            vehicle_errors[i] = error;
            return;
        }
    }
    fprintf(stderr, "Error list full, cannot add new error.\n");
}

void remove_error(uint16_t index) {
    if (index >= MAX_ERRORS || vehicle_errors[index] == NULL) {
        fprintf(stderr, "Invalid index for error removal.\n");
        return;
    }
    free(vehicle_errors[index]);
    vehicle_errors[index] = NULL;
}

SRE_error* check_if_error_exists(uint16_t error_type, uint16_t sub_error_type) {
    for (int i = 0; i < MAX_ERRORS; i++) {
        if (vehicle_errors[i] != NULL && vehicle_errors[i]->error_type == error_type && vehicle_errors[i]->sub_error_type == sub_error_type) {
            return vehicle_errors[i];
        }
    }
    return NULL;
}

/* ---- VEHICLE INFO MANAGEMENT ---*/

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