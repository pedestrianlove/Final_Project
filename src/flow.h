#include <stdio.h>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

typedef struct handle {
	char* TITLE;
	int FPS;
	int WIDTH, HEIGHT;
	
	ALLEGRO_BITMAP *IMAGE;
	ALLEGRO_BITMAP *IMAGE2;
	ALLEGRO_BITMAP *IMAGE3;
	ALLEGRO_BITMAP *BG;
	ALLEGRO_KEYBOARD_STATE KEY_STATE ;

	ALLEGRO_DISPLAY* DISPLAY;
	ALLEGRO_EVENT_QUEUE* EVENT_QUEUE;
	ALLEGRO_SAMPLE* SONG;
	ALLEGRO_TIMER* TIMER;
	ALLEGRO_TIMER* TIMER2;
	ALLEGRO_TIMER* TIMER3;
	ALLEGRO_FONT* FONT;
}handle;

handle* Handle_init ();
void game_init (handle*);
void game_begin (handle*);

void game_destroy (handle*);

void exception (int, char* str, handle*);
