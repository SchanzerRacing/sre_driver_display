
#include <gtk/gtk.h>

GtkWidget* create_parameters_panel() {
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    GtkWidget *label = gtk_label_new("Parameters");
    gtk_box_append(GTK_BOX(box), label);
    return box;
}