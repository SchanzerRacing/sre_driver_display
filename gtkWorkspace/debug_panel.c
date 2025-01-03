#include "headers/debug_panel.h"
#include <gtk/gtk.h>

GtkBuilder *builder_debug_panel = NULL;

GObject *label_tsa = NULL;
GObject *label_r2d = NULL;
GObject *label_brake_pressure_1 = NULL;
GObject *label_brake_pressure_2 = NULL;
GObject *label_hv_power = NULL;
GObject *label_car_state = NULL;
GObject *label_bat_state = NULL;

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
    label_tsa = gtk_builder_get_object(builder_debug_panel, "lbl_tsa");
    label_r2d = gtk_builder_get_object(builder_debug_panel, "lbl_r2d");

    label_brake_pressure_1 = gtk_builder_get_object(builder_debug_panel, "info_brake_pressure_1");
    label_brake_pressure_2 = gtk_builder_get_object(builder_debug_panel, "info_brake_pressure_2");
    label_hv_power = gtk_builder_get_object(builder_debug_panel, "info_hv_power");

    label_car_state = gtk_builder_get_object(builder_debug_panel, "info_car_state");
    label_bat_state = gtk_builder_get_object(builder_debug_panel, "info_bat_state");

    // Add debugpanel to the main box
    gtk_box_append(GTK_BOX(main_dp_box), GTK_WIDGET(debug_panel));

    return main_dp_box;
}