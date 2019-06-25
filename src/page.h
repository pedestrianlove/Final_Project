#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

#include "internal-event.h"
typedef struct control {
	ALLEGRO_EVENT_QUEUE* event_queue;
	ALLEGRO_DISPLAY* display;
	ALLEGRO_STATE* game_state;
	ALLEGRO_STATE* settings_state;
	ALLEGRO_STATE* end_state;
	int stage;
}control;
control* init_control (ALLEGRO_EVENT_QUEUE*, ALLEGRO_DISPLAY*);




int intro_page (control*);
int title_page (control*);
int about_page (control*);
int game_page (control*);
int settings_page (control*);
int exit_page (control*);

