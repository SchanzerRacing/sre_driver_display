#include <gtk/gtk.h>
#include <glib/gstdio.h>
#include <stdlib.h>
#include <time.h>

gboolean periodic_function(gpointer user_data)
{
    printf("periodic_function\n");
    // GtkBuilder *builder = GTK_BUILDER(user_data);
    // GObject *label_tsa = gtk_builder_get_object(builder, "lbl_tsa");
    // printf("label_tsa: %p\n", label_tsa);
    // GObject *label_r2d = gtk_builder_get_object(builder, "lbl_r2d");
    // printf("label_r2d: %p\n", label_r2d);

    // if (label_tsa) {
    //     gtk_widget_add_css_class(GTK_WIDGET(label_tsa), "blink");
    // }

    return TRUE;
}

static void activate (GtkApplication *app, gpointer user_data)
{
    GtkCssProvider *cssProvider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(cssProvider, "../designs/dd.css");

    gtk_style_context_add_provider_for_display(gdk_display_get_default(),
                                               GTK_STYLE_PROVIDER(cssProvider),
                                               GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    // Construct a GtkBuilder instance and load our UI description
    GtkBuilder *builder = gtk_builder_new ();
    GError* error = NULL;
    gtk_builder_add_from_file (builder, "../designs/gtk4-driverdisplay.ui", &error);
    if (error != NULL)
    {
        fprintf(stderr, "Unable to load UI file: %s\n", error->message);
        return;
    }
    
    GObject *window = gtk_builder_get_object(builder, "window_main");
    
    gtk_window_set_application(GTK_WINDOW(window), app);

    gtk_widget_set_visible(GTK_WIDGET(window), TRUE);

    g_timeout_add(100, periodic_function, builder);

    // test_change_labels(builder);
    
    g_object_unref (builder);
}

int main (int argc, char **argv)
{
    GtkApplication *app = gtk_application_new("org.sre.GtkBuilderTests", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}