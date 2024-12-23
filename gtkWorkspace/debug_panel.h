
#ifndef DEBUG_PANEL_H
#define DEBUG_PANEL_H

#include <gtk/gtk.h>

GtkWidget* create_debug_panel();

extern GtkBuilder *builder_debug_panel;

extern GObject *label_tsa;
extern GObject *label_r2d;

#endif