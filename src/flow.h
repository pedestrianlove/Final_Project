#include <stdio.h>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#define SONG_NORMAL 0

typedef struct init_handle {
	const char* TITLE = "Final Project 105021226";
	const int FPS = 60;
	const int WIDTH = 1024, HEIGHT = 768;
	ALLEGRO_DISPLAY* DISPLAY;
	ALLEGRO_EVENT_QUEUE* EVENT_QUEUE;
	ALLEGRO_FONT* FONT;
}init_handle;

void game_init (init_handle*);
void game_begin (init_handle*);

void game_destroy ();
