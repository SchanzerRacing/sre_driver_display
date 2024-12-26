/*
*  This file contains state logics functions.
*/
#include <gtk/gtk.h>
#include <stdio.h>
#include "headers/sre_logic.h"
#include "headers/debug_panel.h"

uint8_t displayCallbackCounter = 0;

SRE_State* sre_state;

void init_sre_state()
{
    printf("init_sre_state\n");
    sre_state = (SRE_State*) malloc(sizeof(SRE_State));
    if(sre_state == NULL)
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
    displayCallbackCounter = ++displayCallbackCounter % 10;
    if(displayCallbackCounter == 9)
    {
        //printf("sre_run_display\n");
    }
    
    tsa_logic();
    r2d_logic();

    // Gathers all the data from the CAN messages and updates the states
    // state_update();

    // Updates the graphical elements
    graphical_update();

    // Updates the labels
    // label_update();

    return G_SOURCE_CONTINUE;
}

void graphical_update()
{
    // printf("graphical_update\n");
    // printf("car_state: %s\n", CAR_STATE_STR[sre_state->car_state]);
    // printf("bat_state: %s\n", BAT_STATE_STR[sre_state->bat_state]);
    
    if(sre_state->tsa_ready)
    {
        gtk_widget_add_css_class(GTK_WIDGET(label_tsa), "blink");
    } else
    {
        gtk_widget_remove_css_class(GTK_WIDGET(label_tsa), "blink");
    }

    if(sre_state->r2d_ready)
    {
        gtk_widget_add_css_class(GTK_WIDGET(label_r2d), "blink");
    } else
    {
        gtk_widget_remove_css_class(GTK_WIDGET(label_r2d), "blink");
    }

    if(sre_state->r2d_active)
    {
        gtk_widget_add_css_class(GTK_WIDGET(label_r2d), "active");
    } else
    {
        gtk_widget_remove_css_class(GTK_WIDGET(label_r2d), "active");
    }

    if(sre_state->tsa_active)
    {
        gtk_widget_add_css_class(GTK_WIDGET(label_tsa), "active");
    } else
    {
        gtk_widget_remove_css_class(GTK_WIDGET(label_tsa), "active");
    }
}

void tsa_logic() 
{
    if(sre_state->car_state == WAIT_FOR_TSA_C && sre_state->bat_state == WAIT_FOR_TSA_B) 
    {
        sre_state->tsa_ready = 1;
    } else 
    {
        sre_state->tsa_ready = 0;
    }

    if(sre_state->bat_state == TSA) 
    {
        sre_state->tsa_active = 1;
    } else 
    {
        sre_state->tsa_active = 0;
    }
}

void r2d_logic()
{
    if(sre_state->car_state == WAIT_FOR_RTD && sre_state->bat_state == TSA) 
    {
        sre_state->r2d_ready = 1;
    } else 
    {
        sre_state->r2d_ready = 0;
    }

    if(sre_state->car_state == DRIVE) 
    {
        sre_state->r2d_active = 1;
    } else 
    {
        sre_state->r2d_active = 0;
    }
}
