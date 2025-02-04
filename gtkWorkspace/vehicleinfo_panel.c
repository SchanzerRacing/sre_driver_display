
#include "headers/vehicleinfo_panel.h"
#include "headers/sre_logic.h"  
#include <gtk/gtk.h>

GtkBuilder *builder_vehicleinfo_panel = NULL;

// PE TEMPS
GObject* info_temp_per_vehicleinfo = NULL;
GObject* info_temp_pef_vehicleinfo = NULL;

// MOTOR TEMPS
GObject* info_temp_motor_fr_vehicleinfo = NULL;
GObject* info_temp_motor_fl_vehicleinfo = NULL;
GObject* info_temp_motor_rr_vehicleinfo = NULL;
GObject* info_temp_motor_rl_vehicleinfo = NULL;

// BATTERY
GObject* info_bat_soc_vehicleinfo = NULL; 
GObject* info_bat_temp_max_vehicleinfo = NULL;
GObject* info_bat_temp_min_vehicleinfo = NULL;
GObject* info_bat_voltage_max_vehicleinfo = NULL;
GObject* info_bat_voltage_min_vehicleinfo = NULL;

// Power Measurement
GObject* info_hv_power_vehicleinfo = NULL;

// Vehicle Info
GObject* info_car_speed_vehicleinfo = NULL;

// STATE
GObject* info_carstate_vehicleinfo = NULL;

// GRAPHICAL ELEMENTS
GObject *label_tsa_vehicleinfo = NULL;
GObject *label_r2d_vehicleinfo = NULL;

GtkWidget* create_vehicleinfo_panel() {
    GtkWidget *main_vehicleinfo_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    //import gtkbuilder ui
    builder_vehicleinfo_panel = gtk_builder_new_from_file("../designs/vehicle-info-panel.ui");
    if(builder_vehicleinfo_panel == NULL) {
        g_print("Failed to load vehicle info builder\n");
        return NULL;
    }

    // Look for debug panel and load it
    GObject *vehicleinfo_panel = gtk_builder_get_object(builder_vehicleinfo_panel, "box_main_vehicleinfo");
    if(vehicleinfo_panel == NULL) {
        g_print("Failed to load vehicle info panel\n");
        return NULL;
    }

    // Remove the parent of debug_panel if it has one
    GtkWidget *parent = gtk_widget_get_parent(GTK_WIDGET(vehicleinfo_panel));
    if (parent != NULL) {
        gtk_widget_unparent(GTK_WIDGET(vehicleinfo_panel));
    }

    // PE TEMPS
    info_temp_per_vehicleinfo = gtk_builder_get_object(builder_vehicleinfo_panel, "info_temp_per_vehicleinfo");
    info_temp_pef_vehicleinfo = gtk_builder_get_object(builder_vehicleinfo_panel, "info_temp_pef_vehicleinfo");

    // MOTOR TEMPS
    info_temp_motor_fr_vehicleinfo = gtk_builder_get_object(builder_vehicleinfo_panel, "info_temp_motor_fr_vehicleinfo");
    info_temp_motor_fl_vehicleinfo = gtk_builder_get_object(builder_vehicleinfo_panel, "info_temp_motor_fl_vehicleinfo");
    info_temp_motor_rr_vehicleinfo = gtk_builder_get_object(builder_vehicleinfo_panel, "info_temp_motor_rr_vehicleinfo");
    info_temp_motor_rl_vehicleinfo = gtk_builder_get_object(builder_vehicleinfo_panel, "info_temp_motor_rl_vehicleinfo");

    // BATTERY
    info_bat_soc_vehicleinfo = gtk_builder_get_object(builder_vehicleinfo_panel, "info_bat_soc_vehicleinfo");
    info_bat_temp_max_vehicleinfo = gtk_builder_get_object(builder_vehicleinfo_panel, "info_bat_temp_max_vehicleinfo");
    info_bat_temp_min_vehicleinfo = gtk_builder_get_object(builder_vehicleinfo_panel, "info_bat_temp_min_vehicleinfo");
    info_bat_voltage_max_vehicleinfo = gtk_builder_get_object(builder_vehicleinfo_panel, "info_bat_voltage_max_vehicleinfo");
    info_bat_voltage_min_vehicleinfo = gtk_builder_get_object(builder_vehicleinfo_panel, "info_bat_voltage_min_vehicleinfo");

    // POWER MEASUREMENT
    info_hv_power_vehicleinfo = gtk_builder_get_object(builder_vehicleinfo_panel, "info_power_vehicleinfo");

    // VEHICLE INFO
    info_car_speed_vehicleinfo = gtk_builder_get_object(builder_vehicleinfo_panel, "info_car_speed_vehicleinfo");

    // STATES
    info_carstate_vehicleinfo = gtk_builder_get_object(builder_vehicleinfo_panel, "info_carstate_vehicleinfo");

    // GRAPHICAL ELEMENTS
    label_tsa_vehicleinfo = gtk_builder_get_object(builder_vehicleinfo_panel, "label_tsa_vehicleinfo");
    label_tsa_current = label_tsa_vehicleinfo;
    label_r2d_vehicleinfo = gtk_builder_get_object(builder_vehicleinfo_panel, "label_r2d_vehicleinfo");
    label_r2d_current = label_r2d_vehicleinfo;
    
    // Add vehicleinfo_panel to the main box
    gtk_box_append(GTK_BOX(main_vehicleinfo_box), GTK_WIDGET(vehicleinfo_panel));
    return main_vehicleinfo_box;
}