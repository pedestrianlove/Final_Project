#include <stdio.h>
#include <allegro5/allegro.h>


typedef struct region {
	float start_x, start_y;
	float end_x, end_y;
}region;


enum PAGE {
	TITLE_PAGE,
	INTRO_PAGE,
	ABOUT_PAGE,
	GAME_PAGE,
	SETTINGS_PAGE,
	EXIT_PAGE,
	HALF_QUIT,
	NO_QUIT
};

enum GAME_ACTION {
	START_PHYSICS,
	START_DRAWING,
	STOP_DRAWING,
	DRAW_TIMER,
	PHYSICS_TIMER,
	SETTINGS,
	WIN,
	EXIT,
	GAME_ON
};

enum SETTINGS {
	RAISE_VOLUME,
	DECREASE_VOLUME,
	EXIT_SETTINGS,
	EXIT_GAME,
	REMAIN_SETTINGS
};

// global
int MOUSE_X;
int MOUSE_Y;

// public internal
int check_position (region**, int, ALLEGRO_MOUSE_STATE*);




// interface
int title_event_handler (ALLEGRO_EVENT_QUEUE*, ALLEGRO_DISPLAY*, region**, int);
int game_event_handler (ALLEGRO_EVENT_QUEUE*, ALLEGRO_DISPLAY*, region**, int, ALLEGRO_TIMER*, ALLEGRO_TIMER*);
int settings_event_handler (ALLEGRO_EVENT_QUEUE*, ALLEGRO_DISPLAY*, region**, int);
int about_event_handler (ALLEGRO_EVENT_QUEUE*, ALLEGRO_DISPLAY*);
int exit_event_handler (ALLEGRO_EVENT_QUEUE*, ALLEGRO_DISPLAY*, region**, int);
region* create_button (float, float, float, float);
