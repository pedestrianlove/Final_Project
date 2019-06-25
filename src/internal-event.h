#include <stdio.h>
#include <allegro5/allegro.h>

typedef struct velocity {
	double x, y;
}velocity;

typedef struct circle {
	double x, y;
	double radius;
	velocity speed;
}circle;

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
	MOVE_FORWARD,
	MOVE_BACKWARD,
	SETTINGS,
};


// public internal
int check_position (region**, int, ALLEGRO_MOUSE_STATE*);




// interface
int title_event_handler (ALLEGRO_EVENT_QUEUE*, ALLEGRO_DISPLAY*, region**, int);
int game_event_handler (ALLEGRO_EVENT_QUEUE*, ALLEGRO_DISPLAY*);
int settings_event_handler (ALLEGRO_EVENT_QUEUE*, ALLEGRO_DISPLAY*);
int about_event_handler (ALLEGRO_EVENT_QUEUE*, ALLEGRO_DISPLAY*);
int exit_event_handler (ALLEGRO_EVENT_QUEUE*, ALLEGRO_DISPLAY*, region**, int);
region* create_button (float, float, float, float);
