// A C GUI App using GTK Framework

#include <stdio.h>
#include <stdlib.h>
#include <gtk-3.0/gtk/gtk.h>
//Added necessary Header files

static int counter = 0;

void on_button_clicked(GtkWidget *widget, gpointer data)
{
    counter++;
    printf("Button clicked %d times\n", counter);
}

void on_button_quit_clicked(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *button_quit;
    GtkWidget *box;
    GtkWidget *label;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "My First GUI App");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), box);

    label = gtk_label_new("Hello World");
    gtk_box_pack_start(GTK_BOX(box), label, TRUE, TRUE, 0);

    button = gtk_button_new_with_label("Click Me");
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(box), button, TRUE, TRUE, 0);

    button_quit = gtk_button_new_with_label("Quit");
    g_signal_connect(button_quit, "clicked", G_CALLBACK(on_button_quit_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(box), button_quit, TRUE, TRUE, 0);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}

//Output:
//Button clicked 1 times
//Button clicked 2 times
