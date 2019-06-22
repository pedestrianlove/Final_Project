#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

typedef struct point {
	int x;
	int y;
}point;


typedef struct object {
	ALLEGRO_BITMAP* AVATAR;
	point POSITION;
	int HP;
}object;
object* init_object (int hp, point position, char* img_path)
{
	object* OBJECT = (object*) malloc (sizeof(object));
	OBJECT -> HP = hp;
	OBJECT -> POSITION = position;
	al_load_bitmap (img_path);
	return OBJECT;
}

// internal
void init_timer (ALLEGRO_TIMER*, ALLEGRO_EVENT_QUEUE*);




// interface
void init_audio ();
void init_display (int, int, char*, ALLEGRO_EVENT_QUEUE*, ALLEGRO_DISPLAY*);
void init_keyboard (ALLEGRO_EVENT_QUEUE* EVENT_QUEUE);

void exception (int, char* str);
