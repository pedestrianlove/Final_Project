#include <allegro5/allegro.h>

enum PAGE {
	TITLE_PAGE,
	ABOUT_PAGE,
	GAME_PAGE,
	SETTINGS_PAGE,
	EXIT_PAGE,
};

enum GAME_ACTION {
	MOVE_FORWARD,
	MOVE_BACKWARD,
	SETTINGS
};


int title_event_handler (ALLEGRO_EVENT_QUEUE*, ALLEGRO_DISPLAY*);
int game_event_handler (ALLEGRO_EVENT_QUEUE*, ALLEGRO_DISPLAY*);
int settings_event_handler (ALLEGRO_EVENT_QUEUE*, ALLEGRO_DISPLAY*);
