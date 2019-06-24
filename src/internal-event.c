#include "internal-event.h"

// different pages need different event handler


int title_event_handler (ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_DISPLAY* display)
{
	ALLEGRO_EVENT event;
	ALLEGRO_MOUSE_STATE mouse_state;
	al_wait_for_event (event_queue, &event);

	switch (event.type) {
		case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
			al_get_mouse_state (&mouse_state);
			break;
		case ALLEGRO_EVENT_KEY_UP:
			if (event.keyboard.keycode == ALLEGRO_KEY_ENTER)
				return GAME_PAGE;
			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				return EXIT_PAGE;
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			return EXIT_PAGE;
			break;
		default:
			return TITLE_PAGE;
			break;

	}
	return TITLE_PAGE;
}


int game_event_handler (ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_DISPLAY* display)
{
	ALLEGRO_EVENT event;
	al_wait_for_event (event_queue, &event);

	switch (event.type) {
		case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
			// create a button handler!FIXME
			break;
		case ALLEGRO_EVENT_KEY_UP:
			if (event.keyboard.keycode == ALLEGRO_KEY_ENTER)
				return GAME_PAGE;
			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				return EXIT_PAGE;
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			return EXIT_PAGE;
			break;
		default:
			return GAME_PAGE;
			break;

	}
	return GAME_PAGE;
}


int settings_event_handler (ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_DISPLAY* display)
{
	return TITLE_PAGE;
}
