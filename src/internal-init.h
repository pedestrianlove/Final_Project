
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

typedef struct dim {
	int WIDTH;
	int HEIGHT;
}dim;


int init_system ();
int init_audio ();
int init_display (ALLEGRO_EVENT_QUEUE**, ALLEGRO_DISPLAY**, dim, char*);
int init_keyboard (ALLEGRO_EVENT_QUEUE**);
int init_font ();
int init_image ();
