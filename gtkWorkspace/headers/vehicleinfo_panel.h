
#ifndef VEHICLEINFO_PANEL_H
#define VEHICLEINFO_PANEL_H

#include <gtk/gtk.h>

GtkWidget* create_vehicleinfo_panel();

extern GtkBuilder *builder_vehicle_info_panel;

// PE TEMPS
extern GObject* info_temp_per_vehicleinfo;
extern GObject* info_temp_pef_vehicleinfo;

// MOTOR TEMPS
extern GObject* info_temp_motor_fr_vehicleinfo;
extern GObject* info_temp_motor_fl_vehicleinfo;
extern GObject* info_temp_motor_rr_vehicleinfo;
extern GObject* info_temp_motor_rl_vehicleinfo;

// BATTERY
extern GObject* info_bat_soc_vehicleinfo; 
extern GObject* info_bat_temp_max_vehicleinfo;
extern GObject* info_bat_temp_min_vehicleinfo;
extern GObject* info_bat_voltage_max_vehicleinfo;
extern GObject* info_bat_voltage_min_vehicleinfo;

// Power Measurement
extern GObject* info_hv_power_vehicleinfo;

// Vehicle Info
extern GObject* info_car_speed_vehicleinfo;

// STATES
extern GObject* info_carstate_vehicleinfo;

// GRAPHICAL ELEMENTS
extern GObject *label_tsa_vehicleinfo;
extern GObject *label_r2d_vehicleinfo;
#endif