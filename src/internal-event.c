#include "internal-event.h"

// different pages need different event handler
region* create_button (float start_x, float start_y, 
				float end_x, float end_y)
{
	region* new_button = malloc (sizeof(region));
	new_button -> start_x = start_x;
	new_button -> start_y = start_y;
	new_button -> end_x = end_x;
	new_button -> end_y = end_y;

	return new_button;
}

int title_event_handler (ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_DISPLAY* display, 
				region** button_list, int list_length)
{
	ALLEGRO_EVENT event;
	ALLEGRO_MOUSE_STATE mouse_state;
	al_wait_for_event (event_queue, &event);

	switch (event.type) {
		case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
			al_get_mouse_state (&mouse_state);
			if (event.mouse.button == 1)
				switch (check_position (button_list, list_length, &mouse_state)) {
					case 0:
						return INTRO_PAGE;
						break;
					case 1:
						return ABOUT_PAGE;
						break;
					case 2:
						return EXIT_PAGE;
						break;
				}
			return TITLE_PAGE;
			break;

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
		case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
			#warning TODO: create a button handler!
			break;
		case ALLEGRO_EVENT_KEY_DOWN:
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
	
#warning TODO: settings implementation
	return SETTINGS_PAGE;
}


int about_event_handler (ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_DISPLAY* display)
{
	ALLEGRO_EVENT event;
	al_wait_for_event (event_queue, &event);

	switch (event.type) {
		case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
			if (event.mouse.button == 1)
				return TITLE_PAGE;
			break;
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			return EXIT_PAGE;
			break;
		default:
			return ABOUT_PAGE;
			break;
	}

	return ABOUT_PAGE;
}


int exit_event_handler (ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_DISPLAY* display, 
				region** button_list, int list_length)
{
	ALLEGRO_EVENT event;
	ALLEGRO_MOUSE_STATE mouse_state;
	al_wait_for_event (event_queue, &event);

	switch (event.type) {
		case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
			al_get_mouse_state (&mouse_state);
			if (event.mouse.button == 1) {
				switch (check_position(button_list, list_length, &mouse_state)) {
					case 0:
						return NO_QUIT;
						break;
					case 1:
						return EXIT_PAGE;
						break;
				}
				return HALF_QUIT;
			}
			
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			return EXIT_PAGE;
			break;
	}
	return HALF_QUIT;
}




// public internal

int check_position (region** button_list, int list_length, ALLEGRO_MOUSE_STATE* mouse_state)
{
	for (int i = 0; i < list_length; i++) {
		if (button_list[i]->start_x <= mouse_state->x &&
				button_list[i]->end_x >= mouse_state->x &&
				button_list[i]->start_y <= mouse_state->y &&
				button_list[i]->end_y >= mouse_state->y)
			return i;
	}
	return -1;
}
