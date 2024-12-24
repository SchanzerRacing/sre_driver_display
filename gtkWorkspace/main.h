#ifndef MAIN_H
#define MAIN_H

#include <gtk/gtk.h>

GtkCssProvider *cssProvider;

GObject *label_tsa;
GObject *label_r2d;

bool tsa_ready;
bool tsa_active;

bool r2d_ready;
bool r2d_active;

#endif // MAIN_H