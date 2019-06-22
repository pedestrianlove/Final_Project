#include "internal-init.h"
#include "internal-error.h"

void init_allegro_system ()
{
	exception (al_init(), 
			"Failed to initialize allegro!");

}

void init_audio ()
{
	exception (al_install_audio(), 
			"Failed to install audio!");
	exception (al_init_acodec_addon(), 
			"Failed to initialize audio codecs!");
	exception (al_reserve_samples(1), 
			"Failed to reserve samples!");
	al_install_audio();
    	al_init_acodec_addon();
}


void init_display (int WIDTH, int HEIGHT, char* TITLE,
			ALLEGRO_EVENT_QUEUE* EVENT_QUEUE, ALLEGRO_DISPLAY* DISPLAY)
{
	// Create display
    	DISPLAY = al_create_display(WIDTH, HEIGHT);
    	EVENT_QUEUE = al_create_event_queue();
    	exception (DISPLAY != NULL && EVENT_QUEUE != NULL, 
			"Failed to initialize the display!"); 
    	al_set_window_position(DISPLAY, 0, 0);
    	al_set_window_title(DISPLAY, TITLE);
	al_register_event_source(EVENT_QUEUE, al_get_display_event_source(DISPLAY));
}


void init_keyboard (ALLEGRO_EVENT_QUEUE* EVENT_QUEUE)
{
    	al_init_primitives_addon();
    	al_install_keyboard();
	al_register_event_source(EVENT_QUEUE, al_get_keyboard_event_source());
}





void exception (int val, char* str) {
	if (!val) {
		show_err_msg(str);
	}
}

