#include "debug_panel.h"
#include <gtk/gtk.h>

// Creates a simple debugging panel
GtkWidget* create_debug_panel() {
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    
    //import gtkbuilder ui
    GtkBuilder *builder = gtk_builder_new_from_file("../xml/driverdisplay-camb.ui");
    GObject *debug_panel = gtk_builder_get_object(builder, "window_main");

    // Ensure the widgets are visible
    gtk_widget_set_visible(GTK_WIDGET(debug_panel),TRUE);

    return box;
}