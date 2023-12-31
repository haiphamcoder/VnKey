#include <gtk/gtk.h>

void end_program(GtkWidget *wid, gpointer ptr)
{
    gtk_main_quit();
}

void open_banggotat(GtkWidget *wid, gpointer ptr)
{
    GtkBuilder *builder = gtk_builder_new();
    if (gtk_builder_add_from_file(builder, "VnKey.glade", NULL) == 0)
    {
        printf("Can not load file\n");
        return;
    }

    GtkWidget *window = GTK_WIDGET(gtk_builder_get_object(builder, "GoTat_Window"));
    g_signal_connect(window, "destroy", G_CALLBACK(end_program), NULL);

    gtk_widget_show_all(window);
}

int main(int argc, char **argv)
{
    gtk_init(&argc, &argv);

    GtkBuilder *builder = gtk_builder_new();
    if (gtk_builder_add_from_file(builder, "VnKey.glade", NULL) == 0)
    {
        printf("Can not load file\n");
        return 0;
    }

    GtkWidget *window = GTK_WIDGET(gtk_builder_get_object(builder, "MainWindow"));
    g_signal_connect(window, "destroy", G_CALLBACK(end_program), NULL);

    GtkWidget *menu_quit = GTK_WIDGET(gtk_builder_get_object(builder, "menu_quit"));
    g_signal_connect(menu_quit, "activate", G_CALLBACK(end_program), NULL);

    GtkWidget *btn_banggotat = GTK_WIDGET(gtk_builder_get_object(builder, "btnBangGoTat"));
    g_signal_connect(btn_banggotat, "clicked", G_CALLBACK(open_banggotat), NULL);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}