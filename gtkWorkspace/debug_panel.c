#include "headers/debug_panel.h"
#include <gtk/gtk.h>

GtkBuilder *builder_debug_panel = NULL;

// PRESSURES
GObject *label_brake_pressure_1 = NULL;
GObject *label_brake_pressure_2 = NULL;
GObject *label_asb_pressure_1 = NULL;
GObject *label_asb_pressure_2 = NULL;

// POWER MEASUREMENT
GObject *label_sdc_power = NULL;
GObject *label_lv_power = NULL;
GObject *label_hv_power = NULL;
GObject *label_epos_power = NULL;

// SWITCH STATES
// TODO

// STATES
GObject *label_car_state = NULL;
GObject *label_bat_state = NULL;
GObject *label_as_state = NULL;
GObject *label_ami_state = NULL;
GObject *label_asb_state = NULL;
GObject *label_sbs_state = NULL;
GObject *label_ebs_state = NULL;
GObject *label_asb_check_sequence = NULL;
GObject *label_asb_trigger_cause = NULL;

// GRAPHICAL ELEMENTS
GObject *label_tsa = NULL;
GObject *label_r2d = NULL;

// Creates a simple debugging panel
GtkWidget* create_debug_panel() {
    GtkWidget *main_dp_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    //import gtkbuilder ui
    builder_debug_panel = gtk_builder_new_from_file("../designs/debug-panel.ui");
    if(builder_debug_panel == NULL) {
        g_print("Failed to load builder\n");
        return NULL;
    }

    // Look for debug panel and load it
    GObject *debug_panel = gtk_builder_get_object(builder_debug_panel, "box_main");
    if(debug_panel == NULL) {
        g_print("Failed to load debug panel\n");
        return NULL;
    }

    // Remove the parent of debug_panel if it has one
    GtkWidget *parent = gtk_widget_get_parent(GTK_WIDGET(debug_panel));
    if (parent != NULL) {
        gtk_widget_unparent(GTK_WIDGET(debug_panel));
    }
    
    // Get the labels and save them for later use

    // PRESSURES
    label_brake_pressure_1 = gtk_builder_get_object(builder_debug_panel, "info_brake_pressure1");
    label_brake_pressure_2 = gtk_builder_get_object(builder_debug_panel, "info_brake_pressure2");
    label_asb_pressure_1 = gtk_builder_get_object(builder_debug_panel, "info_asb_pressure1");
    label_asb_pressure_2 = gtk_builder_get_object(builder_debug_panel, "info_asb_pressure2");

    // POWER MEASUREMENT
    label_sdc_power = gtk_builder_get_object(builder_debug_panel, "info_sdc_power");
    label_lv_power = gtk_builder_get_object(builder_debug_panel, "info_lv_power");
    label_hv_power = gtk_builder_get_object(builder_debug_panel, "info_hv_power");
    label_epos_power = gtk_builder_get_object(builder_debug_panel, "info_epos_power");

    // STATES
    label_car_state = gtk_builder_get_object(builder_debug_panel, "info_car_state");
    label_bat_state = gtk_builder_get_object(builder_debug_panel, "info_bat_state");
    label_as_state = gtk_builder_get_object(builder_debug_panel, "info_as_state");
    label_ami_state = gtk_builder_get_object(builder_debug_panel, "info_ami_state");
    label_asb_state = gtk_builder_get_object(builder_debug_panel, "info_asb_state");
    label_sbs_state = gtk_builder_get_object(builder_debug_panel, "info_sbs_state");
    label_ebs_state = gtk_builder_get_object(builder_debug_panel, "info_ebs_state");
    label_asb_check_sequence = gtk_builder_get_object(builder_debug_panel, "info_asb_cs");
    label_asb_trigger_cause = gtk_builder_get_object(builder_debug_panel, "info_asb_tc");

    // Graphical Elements
    label_tsa = gtk_builder_get_object(builder_debug_panel, "lbl_tsa");
    label_r2d = gtk_builder_get_object(builder_debug_panel, "lbl_r2d");


    // Add debugpanel to the main box
    gtk_box_append(GTK_BOX(main_dp_box), GTK_WIDGET(debug_panel));

    return main_dp_box;
}