#include <gtk/gtk.h>












static gboolean button_press_event_clbk ( GtkWidget *widget, GdkEvent *event )
{
    g_return_val_if_fail ( GTK_IS_LABEL ( widget ), FALSE );

    switch ( event->type )
    {
        case GDK_BUTTON_PRESS :
            printf ( "The Button was Pressed\n" );
            return TRUE;

        case GDK_BUTTON_RELEASE :
            printf ( "\tThe Button was Released\n" );
            return TRUE;

        default:
            return FALSE;
    }

    return FALSE;
}

int main ( void )
{
    GtkWidget *window;
    GtkWidget *label;
    GtkWidget *button;


    gtk_init ( NULL, NULL );
    
    window = gtk_window_new ( GTK_WINDOW_TOPLEVEL );
    gtk_window_set_default_size ( GTK_WINDOW ( window ), 200, 300 );
    g_signal_connect ( window, "delete-event", G_CALLBACK ( gtk_main_quit ), NULL );




    gtk_window_set_title(GTK_WINDOW(window), "Tooltip");
    
    
    





    label = gtk_label_new ( "Click here" );
    /* 
     * --- Create a button
     */

    /* --- Create a new button. --- */
    button = gtk_button_new_with_label ("Button");

    /* --- Show the button  --- */
   
    gtk_container_add ( GTK_CONTAINER ( window ), button );
    

    

    g_signal_connect_swapped ( button, "button-press-event",   G_CALLBACK ( button_press_event_clbk ), label );
    g_signal_connect_swapped ( button, "button-release-event", G_CALLBACK ( button_press_event_clbk ), label );

    gtk_widget_show_all ( window );

    gtk_main ();
}
