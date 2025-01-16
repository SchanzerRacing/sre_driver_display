
#include "headers/endurance_panel.h"
#include <gtk/gtk.h>

GtkBuilder *builder_endu_panel = NULL;

// PE TEMPS
GObject* info_temp_per_endu = NULL;
GObject* info_temp_pef_endu = NULL;

// MOTOR TEMPS
GObject* info_temp_motor_fr_endu = NULL;
GObject* info_temp_motor_fl_endu = NULL;
GObject* info_temp_motor_rr_endu = NULL;
GObject* info_temp_motor_rl_endu = NULL;

// BATTERY
GObject* info_bat_soc_endu = NULL; 
GObject* info_battemp_max_endu = NULL;

// STATE
GObject* info_carstate_endu = NULL;

// GRAPHICAL ELEMENTS
GObject *label_tsa_endu = NULL;
GObject *label_r2d_endu = NULL;

GtkWidget* create_endurance_panel() {
    GtkWidget *main_endu_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    //import gtkbuilder ui
    builder_endu_panel = gtk_builder_new_from_file("../designs/endurance-panel.ui");
    if(builder_endu_panel == NULL) {
        g_print("Failed to load builder\n");
        return NULL;
    }

    // Look for debug panel and load it
    GObject *endu_panel = gtk_builder_get_object(builder_endu_panel, "box_main_endu");
    if(endu_panel == NULL) {
        g_print("Failed to load endurance panel\n");
        return NULL;
    }

    // Remove the parent of debug_panel if it has one
    GtkWidget *parent = gtk_widget_get_parent(GTK_WIDGET(endu_panel));
    if (parent != NULL) {
        gtk_widget_unparent(GTK_WIDGET(endu_panel));
    }

    // PE TEMPS
    info_temp_per_endu = gtk_builder_get_object(builder_endu_panel, "info_temp_per_endu");
    info_temp_pef_endu = gtk_builder_get_object(builder_endu_panel, "info_temp_pef_endu");

    // MOTOR TEMPS
    info_temp_motor_fr_endu = gtk_builder_get_object(builder_endu_panel, "info_motor_temp_fr_endu");
    info_temp_motor_fl_endu = gtk_builder_get_object(builder_endu_panel, "info_motor_temp_fl_endu");
    info_temp_motor_rr_endu = gtk_builder_get_object(builder_endu_panel, "info_motor_temp_rr_endu");
    info_temp_motor_rl_endu = gtk_builder_get_object(builder_endu_panel, "info_motor_temp_rl_endu");

    // BATTERY
    info_bat_soc_endu = gtk_builder_get_object(builder_endu_panel, "info_soc_endu");
    info_battemp_max_endu = gtk_builder_get_object(builder_endu_panel, "info_battemp_max_endu");

    // STATE
    info_carstate_endu = gtk_builder_get_object(builder_endu_panel, "info_carstate_endu");

    // GRAPHICAL ELEMENTS
    label_tsa_endu = gtk_builder_get_object(builder_endu_panel, "label_tsa_endu");
    label_r2d_endu = gtk_builder_get_object(builder_endu_panel, "label_r2d_endu");
    
    // Add endu_panel to the main box
    gtk_box_append(GTK_BOX(main_endu_box), GTK_WIDGET(endu_panel));
    return main_endu_box;
}