/*

    Main file to experiment and test app development in C!

*/

#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

static void activate(GtkApplication* app, gpointer user_data) {
    // create a pointer of type GtkWidget for a window and for a label
    GtkWidget *window;
    GtkWidget *label;

    window = gtk_application_window_new(app);
    label = gtk_label_new("Hello GNOMEEEE!!1!");
    // the window gets assigned a window and
    // the label gets assigned a label.


    gtk_container_add (GTK_CONTAINER (window), label);
    gtk_window_set_title(GTK_WINDOW (window), "Welcome to GNOME");
    gtk_window_set_default_size(GTK_WINDOW (window), 400, 400);
    gtk_widget_show_all(window);

}


int main(int argc, char **argv) {
    // create a pointer to an object type GtkApplication called app
    //This is the window itself
    GtkApplication *app;
    // This int just show if the app should be running or not
    int status;




    #if GLIB_CHECK_VERSION(2, 36, 0)
        app = gtk_application_new(NULL, G_APPLICATION_DEFAULT_FLAGS);
    #else
        app = gtk_application_new(NULL, G_APPLICATION_FLAGS_NONE);
    #endif
    // This is a pre processor directive
    // It checks for the version of the GLIB, if it's 2.36, it uses default flags, otherwise it uses no flags.


        g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
        //This portion handles the signal detection and response
        // app is the object transmitting signals, "activate" happens when the app is ready to go.

        status = g_application_run(G_APPLICATION(app), argc, argv);
        g_object_unref(app);

    return status;
}