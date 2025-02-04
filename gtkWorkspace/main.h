#ifndef MAIN_H
#define MAIN_H

#include <gtk/gtk.h>

#include <pthread.h>

#define GUI_UPDATE_INTERVALL 500 // ms

pthread_t can_thread;

GtkCssProvider *cssProvider;

bool tsa_ready;
bool tsa_active;

bool r2d_ready;
bool r2d_active;

int panel_index;

/// @brief Callback for on_click event when the user clicks anywhere in the gtk window
/// @param gesture 
/// @param n_press 
/// @param x 
/// @param y 
/// @param user_data 
/// @return 
static gboolean on_click(GtkGestureClick *gesture, gint n_press, 
        gdouble x, gdouble y, gpointer user_data);

/// @brief registers any key release events
/// @param controller 
/// @param keyval 
/// @param keycode 
/// @param state 
/// @param user_data 
static void event_key_release_cb (GtkEventControllerKey *controller, 
    guint keyval, guint keycode, GdkModifierType state, gpointer user_data);

/// @brief Activates the GTK application
static void activate(GtkApplication *app, gpointer user_data);


#endif // MAIN_H