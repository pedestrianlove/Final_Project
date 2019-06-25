#include "internal-init.h"


int init_system ()
{
	return al_init ();
}


int init_audio ()
{
	return al_install_audio () &&
		al_init_acodec_addon () &&
		al_reserve_samples (1);
}


int init_display (ALLEGRO_EVENT_QUEUE** event_queue, ALLEGRO_DISPLAY** display, 
			dim dimension, char* title)
{
	// Create display
    	*display = al_create_display(dimension.WIDTH, dimension.HEIGHT);
    	*event_queue = al_create_event_queue();
	if (*display == NULL || *event_queue == NULL) 
        	return 0;

    	al_set_window_position(*display, 0, 0);
    	al_set_window_title(*display, title);
	
	al_register_event_source (*event_queue, al_get_display_event_source (*display));
	return 1;
}


int init_keyboard (ALLEGRO_EVENT_QUEUE** event_queue)
{
	al_init_primitives_addon ();
	if (!(al_install_keyboard () && al_install_mouse ()))
		return 0;
    	al_register_event_source (*event_queue, al_get_keyboard_event_source ());
	al_register_event_source (*event_queue, al_get_mouse_event_source ());
	return 1;
}


int init_font ()
{
	return al_init_font_addon() &&
		al_init_ttf_addon();
}

int init_image ()
{
    	return al_init_image_addon();
}
