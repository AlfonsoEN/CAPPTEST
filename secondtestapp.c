/*

Second testing app! I am attempting to build a new app, but this time with a button on it.

*/

#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

static void activate(GtkApplication *app, g pointer user_data){
    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *button;


    window = gtk_application_window_new(app);
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    button = gtk_button_new_with_label("Click me!");

    gtk_container_add( GTK_WINDOW(window), box);
    gtk_window_set_title(GTK_WINDOW(window), "Second Gnome App");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    gtk_widget_show(window);


}



int main(int argc, char *argv) {

    GtkApplication *app;
    int status;

    #if GLIB_CHECK_VERSION(2, 36, 0)
        app = gtk_application_new(NULL, G_APPLICATION_DEFAULT_FLAGS);
    #else
        app = gtk_application_new(NULL, G_APPLICATION_FLAGS_NONE):
    #endif


    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);

    g_object_unref(app);


    return status;
}