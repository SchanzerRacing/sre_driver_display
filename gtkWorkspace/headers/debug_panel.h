
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
// TODO

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

// GRAPHICAL ELEMENTS
extern GObject *label_tsa;
extern GObject *label_r2d;

#endif