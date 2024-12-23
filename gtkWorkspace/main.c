#include <gtk/gtk.h>
#include "debug_panel.h"
#include "endurance_panel.h"
#include "parameters_panel.h"
#include "main.h"

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

static void event_key_release_cb (GtkEventControllerKey *controller, guint keyval, guint keycode, GdkModifierType state, gpointer user_data) {
    printf("Key released: %d\n", keyval);
    if (keyval == GDK_KEY_t) {
        printf("Key t released\n");
        tsa_ready = !tsa_ready;
        // activate Blinking css
        if(tsa_ready)
            gtk_widget_add_css_class(GTK_WIDGET(label_tsa), "blink");
        else if(!tsa_ready)
            gtk_widget_remove_css_class(GTK_WIDGET(label_tsa), "blink");
    } else if(keyval == GDK_KEY_r) {
        printf("Key r released\n");
        r2d_ready = !r2d_ready;
        // activate Blinking css
        if(r2d_ready)
            gtk_widget_add_css_class(GTK_WIDGET(label_r2d), "blink");
        else if(!r2d_ready)
            gtk_widget_remove_css_class(GTK_WIDGET(label_r2d), "blink");
    } else if(keyval == GDK_KEY_f) {
        printf("Key f released\n");
        r2d_active = !r2d_active;
        // activate active css
        if(r2d_active)
            gtk_widget_add_css_class(GTK_WIDGET(label_r2d), "active");
        else if(!r2d_active)
            gtk_widget_remove_css_class(GTK_WIDGET(label_r2d), "active");
    } else if(keyval == GDK_KEY_g) {
        printf("Key g released\n");
        tsa_active = !tsa_active;
        // activate active css
        if(tsa_active)
            gtk_widget_add_css_class(GTK_WIDGET(label_tsa), "active");
        else if(!tsa_active)
            gtk_widget_remove_css_class(GTK_WIDGET(label_tsa), "active");
    } 
}

static void activate(GtkApplication *app, gpointer user_data) {
    cssProvider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(cssProvider, "../designs/dd.css");

    gtk_style_context_add_provider_for_display(gdk_display_get_default(),
                                               GTK_STYLE_PROVIDER(cssProvider),
                                               GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);


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

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char *argv[]) {
    GtkApplication *app = gtk_application_new("org.fsae.driverdisplay", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    // g_timeout_add(100, (GSourceFunc) sre_run_display, NULL); 

    // Example usage
    parse_dbc_file("BODY-CAN.dbc");

    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
