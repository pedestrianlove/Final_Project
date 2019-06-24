#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

#include "internal-event.h"
typedef struct control {
	ALLEGRO_EVENT_QUEUE* event_queue;
	ALLEGRO_DISPLAY* display;
}control;
control* init_control (ALLEGRO_EVENT_QUEUE*, ALLEGRO_DISPLAY*);




int title_page (control*);
int about_page (control*);
int game_page (control*);
int settings_page (control*);
int exit_page (control*);

