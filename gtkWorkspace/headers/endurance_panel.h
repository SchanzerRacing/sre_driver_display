
#ifndef ENDURANCE_PANEL_H
#define ENDURANCE_PANEL_H

#include <gtk/gtk.h>

GtkWidget* create_endurance_panel();

extern GtkBuilder *builder_endu_panel;

// PE TEMPS
extern GObject* info_temp_per_endu;
extern GObject* info_temp_pef_endu;

// MOTOR TEMPS
extern GObject* info_temp_motor_fr_endu;
extern GObject* info_temp_motor_fl_endu;
extern GObject* info_temp_motor_rr_endu;
extern GObject* info_temp_motor_rl_endu;

// BATTERY
extern GObject* info_bat_soc_endu;
extern GObject* info_bat_temp_max_endu;

// STATE
extern GObject* info_carstate_endu;

// GRAPHICAL ELEMENTS
extern GObject *label_tsa_endu;
extern GObject *label_r2d_endu;
#endif