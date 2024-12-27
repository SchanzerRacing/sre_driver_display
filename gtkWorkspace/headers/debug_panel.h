
#ifndef DEBUG_PANEL_H
#define DEBUG_PANEL_H

#include <gtk/gtk.h>

GtkWidget* create_debug_panel();

extern GtkBuilder *builder_debug_panel;

extern GObject *label_tsa;
extern GObject *label_r2d;

extern GObject *label_brake_pressure_1;
extern GObject *label_brake_pressure_2;
extern GObject *label_hv_power;

extern GObject *label_car_state;
extern GObject *label_bat_state;


#endif