
#ifndef DEBUG_PANEL_H
#define DEBUG_PANEL_H

#include <gtk/gtk.h>

GtkWidget* create_debug_panel();

extern GtkBuilder *builder_debug_panel;

// PRESSURES
extern GObject *label_brake_pressure_1;
extern GObject *label_brake_pressure_2;
extern GObject *label_asb_pressure_1;
extern GObject *label_asb_pressure_2;

// POWER MEASUREMENT
extern GObject *label_sdc_power;
extern GObject *label_lv_power;
extern GObject *label_hv_power;
extern GObject *label_epos_power;

// SWITCH STATES
extern GObject *label_acu_switch_state;
extern GObject *label_asb_switch_state;
extern GObject *label_dash_switch_state;
extern GObject *label_epos_switch_state;
extern GObject *label_fan_l_switch_state;
extern GObject *label_fan_r_switch_state;
extern GObject *label_sbg_switch_state;
extern GObject *label_vcu_switch_state;
extern GObject *label_pef_switch_state;
extern GObject *label_per_switch_state;
extern GObject *label_pumps_switch_state;
extern GObject *label_sensors_switch_state;

// STATES
extern GObject *label_car_state;
extern GObject *label_bat_state;
extern GObject *label_as_state;
extern GObject *label_ami_state;
extern GObject *label_asb_state;
extern GObject *label_sbs_state;
extern GObject *label_ebs_state;
extern GObject *label_asb_check_sequence;
extern GObject *label_asb_trigger_cause;

// VEHICLE ERRORS
#define ERROR_LABEL_COUNT 9
extern GObject* error_array[ERROR_LABEL_COUNT][2];

extern GObject *label_error_1;
extern GObject *label_error_2;
extern GObject *label_error_3;
extern GObject *label_error_4;
extern GObject *label_error_5;
extern GObject *label_error_6;
extern GObject *label_error_7;
extern GObject *label_error_8;
extern GObject *label_error_9;

extern GObject *info_error_1;
extern GObject *info_error_2;
extern GObject *info_error_3;
extern GObject *info_error_4;
extern GObject *info_error_5;
extern GObject *info_error_6;
extern GObject *info_error_7;
extern GObject *info_error_8;
extern GObject *info_error_9;

// GRAPHICAL ELEMENTS
extern GObject *label_tsa;
extern GObject *label_r2d;

#endif
