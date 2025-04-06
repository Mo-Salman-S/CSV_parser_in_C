#include <gtk/gtk.h>
#include "csv_parser.h"
static void on_open_clicked(GtkWidget *widget, gpointer data) {
    g_print("Open CSV button clicked\n");
    

}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "CSV Parser");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *button = gtk_button_new_with_label("Open CSV");
    g_signal_connect(button, "clicked", G_CALLBACK(on_open_clicked), NULL);

    gtk_container_add(GTK_CONTAINER(window), button);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
