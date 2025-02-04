#include "headers/debug_panel.h"
#include "headers/sre_logic.h"
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

// VEHICLE ERRORS
GObject *label_error_1 = NULL;
GObject *label_error_2 = NULL;
GObject *label_error_3 = NULL;
GObject *label_error_4 = NULL;
GObject *label_error_5 = NULL;
GObject *label_error_6 = NULL;
GObject *label_error_7 = NULL;
GObject *label_error_8 = NULL;
GObject *label_error_9 = NULL;

GObject *info_error_1 = NULL;
GObject *info_error_2 = NULL;
GObject *info_error_3 = NULL;
GObject *info_error_4 = NULL;
GObject *info_error_5 = NULL;
GObject *info_error_6 = NULL;
GObject *info_error_7 = NULL;
GObject *info_error_8 = NULL;
GObject *info_error_9 = NULL;

GObject* error_array[ERROR_LABEL_COUNT][2];

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

    // VEHICLE ERRORS
    label_error_1 = gtk_builder_get_object(builder_debug_panel, "lbl_error_1");
    label_error_2 = gtk_builder_get_object(builder_debug_panel, "lbl_error_2");
    label_error_3 = gtk_builder_get_object(builder_debug_panel, "lbl_error_3");
    label_error_4 = gtk_builder_get_object(builder_debug_panel, "lbl_error_4");
    label_error_5 = gtk_builder_get_object(builder_debug_panel, "lbl_error_5");
    label_error_6 = gtk_builder_get_object(builder_debug_panel, "lbl_error_6");
    label_error_7 = gtk_builder_get_object(builder_debug_panel, "lbl_error_7");
    label_error_8 = gtk_builder_get_object(builder_debug_panel, "lbl_error_8");
    label_error_9 = gtk_builder_get_object(builder_debug_panel, "lbl_error_9");

    info_error_1 = gtk_builder_get_object(builder_debug_panel, "info_error_1");
    info_error_2 = gtk_builder_get_object(builder_debug_panel, "info_error_2");
    info_error_3 = gtk_builder_get_object(builder_debug_panel, "info_error_3");
    info_error_4 = gtk_builder_get_object(builder_debug_panel, "info_error_4");
    info_error_5 = gtk_builder_get_object(builder_debug_panel, "info_error_5");
    info_error_6 = gtk_builder_get_object(builder_debug_panel, "info_error_6");
    info_error_7 = gtk_builder_get_object(builder_debug_panel, "info_error_7");
    info_error_8 = gtk_builder_get_object(builder_debug_panel, "info_error_8");
    info_error_9 = gtk_builder_get_object(builder_debug_panel, "info_error_9");

    error_array[0][0] = label_error_1;
    error_array[0][1] = info_error_1;
    error_array[1][0] = label_error_2;
    error_array[1][1] = info_error_2;
    error_array[2][0] = label_error_3;
    error_array[2][1] = info_error_3;
    error_array[3][0] = label_error_4;
    error_array[3][1] = info_error_4;
    error_array[4][0] = label_error_5;
    error_array[4][1] = info_error_5;
    error_array[5][0] = label_error_6;
    error_array[5][1] = info_error_6;
    error_array[6][0] = label_error_7;
    error_array[6][1] = info_error_7;
    error_array[7][0] = label_error_8;
    error_array[7][1] = info_error_8;
    error_array[8][0] = label_error_9;
    error_array[8][1] = info_error_9;

    // Graphical Elements
    label_tsa = gtk_builder_get_object(builder_debug_panel, "lbl_tsa");
    label_tsa_current = label_tsa;
    label_r2d = gtk_builder_get_object(builder_debug_panel, "lbl_r2d");
    label_r2d_current = label_r2d;

    // Add debugpanel to the main box
    gtk_box_append(GTK_BOX(main_dp_box), GTK_WIDGET(debug_panel));

    return main_dp_box;
}