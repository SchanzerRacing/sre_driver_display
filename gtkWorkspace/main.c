#include <gtk/gtk.h>
#include "headers/sre_logic.h"
#include "headers/debug_panel.h"
#include "headers/endurance_panel.h"
#include "headers/parameters_panel.h"
#include "main.h"

// external functions
GtkWidget* create_endurance_panel();
GtkWidget* create_parameters_panel();

static gboolean on_click(GtkGestureClick *gesture, gint n_press, gdouble x, gdouble y, gpointer user_data);

// Placeholder for reading/decoding BODY-CAN.dbc
static void parse_dbc_file(const char *dbc_path) {
    // TODO: Implement CAN DBC parsing logic
}

static void switch_panel(GtkWidget *window, const char *panel_name) {
    GtkWidget *panel;
    if (g_strcmp0(panel_name, "Endurance") == 0) {
        panel = create_endurance_panel();
    } else if (g_strcmp0(panel_name, "Parameters") == 0) {
        panel = create_parameters_panel();
    } else {
        panel = create_debug_panel();
    }
    gtk_window_set_child(GTK_WINDOW(window), panel);
}

static gboolean on_click(GtkGestureClick *gesture, gint n_press, gdouble x, gdouble y, gpointer user_data) {
    static int panel_index = 0;
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

    // Initial panel
    GtkWidget *initial_panel = create_debug_panel();
    gtk_window_set_child(GTK_WINDOW(window), initial_panel);

    // Add Key Press Event Controller
    GtkEventController *key_controller = gtk_event_controller_key_new();
    g_signal_connect_object(key_controller, "key-released", 
                            G_CALLBACK(event_key_release_cb), 
                            window, G_CONNECT_SWAPPED);
    gtk_widget_add_controller(window, key_controller);

    // Create a GtkGestureClick and connect it to the on_click function
    GtkGesture *click = gtk_gesture_click_new();
    g_signal_connect(click, "pressed", G_CALLBACK(on_click), window);
    gtk_widget_add_controller(window, GTK_EVENT_CONTROLLER(click));

    g_timeout_add(250, (GSourceFunc) sre_run_display, NULL);

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char *argv[]) 
{
    GtkApplication *app = gtk_application_new("org.fsae.driverdisplay", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);


    // Example usage
    parse_dbc_file("BODY-CAN.dbc");
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
