#ifndef MAIN_H
#define MAIN_H

#include <gtk/gtk.h>

GtkCssProvider *cssProvider;

GObject *label_tsa;
GObject *label_r2d;

bool tsa_ready = false;
bool tsa_active = false;

bool r2d_ready = false;
bool r2d_active = false;

#endif // MAIN_H