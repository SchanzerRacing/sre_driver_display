#include <gtk/gtk.h>
#include "debug_panel.h"
#include "endurance_panel.h"
#include "parameters_panel.h"

// Placeholder for reading/decoding BODY-CAN.dbc
static void parse_dbc_file(const char *dbc_path) {
    // TODO: Implement CAN DBC parsing logic
}

// Function prototypes for panel creation
GtkWidget* create_endurance_panel();
GtkWidget* create_parameters_panel();

static gboolean on_click(GtkGestureClick *gesture, gint n_press, gdouble x, gdouble y, gpointer user_data);

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

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Driver Display");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 480);

    // Initial panel
    GtkWidget *initial_panel = create_debug_panel();
    gtk_window_set_child(GTK_WINDOW(window), initial_panel);

    // Create a GtkGestureClick and connect it to the on_click function
    GtkGesture *click = gtk_gesture_click_new();
    g_signal_connect(click, "pressed", G_CALLBACK(on_click), window);
    gtk_widget_add_controller(window, GTK_EVENT_CONTROLLER(click));

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char *argv[]) {
    GtkApplication *app = gtk_application_new("org.fsae.driverdisplay", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    // Example usage
    parse_dbc_file("BODY-CAN.dbc");

    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
