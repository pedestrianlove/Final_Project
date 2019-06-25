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


int game_event_handler (ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_DISPLAY* display, 
				region** button_list, int list_length, ALLEGRO_TIMER* physics, ALLEGRO_TIMER* draw)
{
	ALLEGRO_EVENT event;
	ALLEGRO_MOUSE_STATE mouse_state;
	al_wait_for_event (event_queue, &event);

	switch (event.type) {
		case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
			al_get_mouse_state (&mouse_state);
			printf("detected mouse button down\n");
			if (event.mouse.button == 1) {
				MOUSE_X = mouse_state.x;
				MOUSE_Y = mouse_state.y;
				return START_DRAWING;
			}
			break;
		case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
			al_get_mouse_state (&mouse_state);
			printf("detected mouse button up\n");
			if (event.mouse.button == 1)
				switch (check_position (button_list, list_length, &mouse_state)) {
					case 0:
						return SETTINGS;
						break;
					case 1:
						return START_PHYSICS;
						break;
					default:
						return STOP_DRAWING;
						break;
				}
			break;
		case ALLEGRO_EVENT_TIMER:
			printf("detected timer event\n");
			if (event.timer.source == physics)
				return PHYSICS_TIMER;
			else
				return DRAW_TIMER;
			break;
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			return EXIT;
			break;

	}
	return GAME_ON;
}


int settings_event_handler (ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_DISPLAY* display,
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
						return RAISE_VOLUME;
						break;
					case 1:
						return DECREASE_VOLUME;
						break;
					default:
						break;
				}
		case ALLEGRO_EVENT_KEY_UP:
			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				return EXIT_SETTINGS;

		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			return EXIT_GAME;
	}

	
#warning TODO: settings implementation
	return REMAIN_SETTINGS;
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
