#include "debug_panel.h"
#include <gtk/gtk.h>

GtkBuilder *builder_debug_panel = NULL;

// Creates a simple debugging panel
GtkWidget* create_debug_panel() {
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    //import gtkbuilder ui
    builder_debug_panel = gtk_builder_new_from_file("../designs/gtk4-driverdisplay.ui");
    if(builder_debug_panel == NULL) {
        g_print("Failed to load builder\n");
        return NULL;
    }

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
    
    label_tsa = gtk_builder_get_object(builder_debug_panel, "lbl_tsa");
    label_r2d = gtk_builder_get_object(builder_debug_panel, "lbl_r2d");

    // Ensure the widgets are visible
    gtk_box_append(GTK_BOX(box), GTK_WIDGET(debug_panel));

    return box;
}