#include <gtk/gtk.h>

#include "headers/sre_logic.h"
#include "headers/sre_can.h"
#include "headers/debug_panel.h"
#include "headers/endurance_panel.h"
#include "headers/parameters_panel.h"
#include "headers/objects.h"
#include "main.h"

// external functions
GtkWidget* create_endurance_panel();
GtkWidget* create_parameters_panel();

GObject* box_error = NULL;
GObject* box_info = NULL; 

GObject *info_error_type = NULL;
GObject *info_error_message = NULL;

GObject *info_info_type = NULL;
GObject *info_info_message = NULL;

GtkBuilder *builder_error_info_panel = NULL;

static gboolean on_click(GtkGestureClick *gesture, gint n_press, gdouble x, gdouble y, gpointer user_data);

static void switch_panel(GtkWidget *widget, const char *panel_name) {
    GtkWidget *panel;
    if (g_strcmp0(panel_name, "Endurance") == 0) {
        panel = create_endurance_panel();
    } else if (g_strcmp0(panel_name, "Parameters") == 0) {
        panel = create_parameters_panel();
    } else {
        panel = create_debug_panel();
    }
    gtk_overlay_set_child(GTK_OVERLAY(widget), panel);
}

static gboolean on_click(GtkGestureClick *gesture, gint n_press, gdouble x, gdouble y, gpointer user_data) {
    static int panel_index = 1;
    const char *panels[] = {"Endurance", "Debug", "Parameters"};
    panel_index = (panel_index + 1) % 3;
    switch_panel(GTK_WIDGET(user_data), panels[panel_index]);
    return TRUE;
}

static void event_key_release_cb (GtkEventControllerKey *controller, guint keyval, guint keycode, GdkModifierType state, gpointer user_data) {
    printf("Key released: %d\n", keyval);
    if (keyval == GDK_KEY_t)
    {
        printf("Key t released\n");
        if(sre_state->car_state == WAIT_FOR_TSA_C)
        {
            sre_state->car_state = UNDEFINED_C;
        } else 
        {
            sre_state->car_state = WAIT_FOR_TSA_C;
        }
    } else if(keyval == GDK_KEY_r) 
    {
        printf("Key r released\n");
        if(sre_state->car_state == WAIT_FOR_RTD)
        {
            sre_state->car_state = UNDEFINED_C;
        } else 
        {
            sre_state->car_state = WAIT_FOR_RTD;
        }
    } else if(keyval == GDK_KEY_f) 
    {
        printf("Key f released\n");
        if(sre_state->car_state == DRIVE)
        {
            sre_state->car_state = UNDEFINED_C;
        } else 
        {
            sre_state->car_state = DRIVE;
        }
    } else if(keyval == GDK_KEY_g) 
    {
        printf("Key g released\n");
        if(sre_state->bat_state == TSA)
        {
            sre_state->bat_state = UNDEFINED_B;
        } else 
        {
            sre_state->bat_state = TSA;
        }
    } else if(keyval == GDK_KEY_b)
    {
        printf("Key b released\n");
        if(sre_state->bat_state == WAIT_FOR_TSA_B)
        {
            sre_state->bat_state = UNDEFINED_B;
        } else 
        {
            sre_state->bat_state = WAIT_FOR_TSA_B;
        }
    }
}

static void activate(GtkApplication *app, gpointer user_data) 
{
    init_sre_state();

    // Load CSS
    cssProvider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(cssProvider, "../designs/dd.css");

    // Apply CSS
    gtk_style_context_add_provider_for_display(gdk_display_get_default(),
                                               GTK_STYLE_PROVIDER(cssProvider),
                                               GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    // Create a new window
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Driver Display");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 480);

    // Create the main overlay
    GtkWidget *main_overlay = gtk_overlay_new();

    // Disallow being a target
    gtk_widget_set_can_target(GTK_WIDGET(main_overlay), FALSE);
    
    // Initial panel
    GtkWidget *initial_panel = create_debug_panel();
    gtk_overlay_set_child(GTK_OVERLAY(main_overlay), initial_panel);

    // Add Key Press Event Controller
    GtkEventController *key_controller = gtk_event_controller_key_new();
    g_signal_connect_object(key_controller, "key-released", 
                            G_CALLBACK(event_key_release_cb), 
                            window, G_CONNECT_SWAPPED);
    gtk_widget_add_controller(window, key_controller);

    // Create a GtkGestureClick and connect it to the on_click function
    GtkGesture *click = gtk_gesture_click_new();
    g_signal_connect(click, "pressed", G_CALLBACK(on_click), main_overlay);
    gtk_widget_add_controller(window, GTK_EVENT_CONTROLLER(click));


    // Create Error and Info Overlays
    builder_error_info_panel = gtk_builder_new_from_file("../designs/error-info-panels.ui");
    if(builder_error_info_panel == NULL) {
        g_print("Failed to load builder\n");
    }

    // Import error Box
    box_error = gtk_builder_get_object(builder_error_info_panel, "box_error");
    if(box_error == NULL) {
        g_print("Failed to load debug panel\n");
    }

    // Import Info Box
    box_info = gtk_builder_get_object(builder_error_info_panel, "box_info");
    if(box_info == NULL) {
        g_print("Failed to load debug panel\n");
    }

    // Remove the parent of error box if it has one
    GtkWidget *parent_error = gtk_widget_get_parent(GTK_WIDGET(box_error));
    if (parent_error != NULL) {
        gtk_widget_unparent(GTK_WIDGET(box_error));
    }

    // Remove the parent of info box if it has one
    GtkWidget *parent_info = gtk_widget_get_parent(GTK_WIDGET(box_info));
    if (parent_info != NULL) {
        gtk_widget_unparent(GTK_WIDGET(box_info));
    }

    info_error_type = gtk_builder_get_object(builder_error_info_panel, "info_error_type");
    info_error_message = gtk_builder_get_object(builder_error_info_panel, "info_error_message");

    info_info_type = gtk_builder_get_object(builder_error_info_panel, "info_info_type");
    info_info_message = gtk_builder_get_object(builder_error_info_panel, "info_info_message");

    // Center alignment of error and info box
    gtk_widget_set_halign(GTK_WIDGET(box_error), GTK_ALIGN_CENTER);
    gtk_widget_set_valign(GTK_WIDGET(box_error), GTK_ALIGN_CENTER);
    gtk_widget_set_halign(GTK_WIDGET(box_info), GTK_ALIGN_CENTER);
    gtk_widget_set_valign(GTK_WIDGET(box_info), GTK_ALIGN_END);

    // Add error and info box to the main overlay
    gtk_overlay_add_overlay(GTK_OVERLAY(main_overlay), GTK_WIDGET(box_error));
    gtk_widget_set_visible(GTK_WIDGET(box_error), FALSE);

    gtk_overlay_add_overlay(GTK_OVERLAY(main_overlay), GTK_WIDGET(box_info));
    gtk_widget_set_visible(GTK_WIDGET(box_info), FALSE);

    // timer that calls the display run function every 250ms
    g_timeout_add(250, (GSourceFunc) sre_run_display, NULL);

    // Add the main overlay to the window
    gtk_window_set_child(GTK_WINDOW(window), main_overlay);

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char *argv[]) 
{
    setup_can();

    // Setup CAN daughter thread
    if (pthread_create(&can_thread, NULL, &can_loop, NULL) != 0) {
        perror("Failed to create CAN thread");
        exit(EXIT_FAILURE);
    }

    GtkApplication *app = gtk_application_new("org.fsae.driverdisplay", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    // close socket
    close_can();

    return status;
}
