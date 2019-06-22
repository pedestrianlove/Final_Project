#include <stdio.h>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>


// custom types
#include "internal-init.h"



typedef struct handle {
	char* TITLE;
	int FPS;
	int WIDTH, HEIGHT;
	int WINDOW;
	
	object* Reddie;
	object* Enemy;

	ALLEGRO_BITMAP* IMAGE;
	ALLEGRO_BITMAP* IMAGE2;
	ALLEGRO_BITMAP* IMAGE3;
	ALLEGRO_BITMAP *BG;
	
	ALLEGRO_KEYBOARD_STATE KEY_STATE ;
	ALLEGRO_DISPLAY* DISPLAY;
	ALLEGRO_EVENT_QUEUE* EVENT_QUEUE;
	
	ALLEGRO_SAMPLE* SONG;
	ALLEGRO_FONT* FONT;
	
	ALLEGRO_TIMER* TIMER[3];
}handle;
handle* Handle_init ()
{
	handle* Handle = (handle*) malloc (sizeof(handle));

	Handle -> TITLE = "Final Project 105021226";
	Handle -> FPS = 60;
	Handle -> WIDTH = 1024;
	Handle -> HEIGHT = 768;

	Handle -> DISPLAY = NULL;
	Handle -> EVENT_QUEUE = NULL;

	Handle -> IMAGE = NULL;
	Handle -> IMAGE2 = NULL;
	Handle -> IMAGE3 = NULL;
	Handle -> BG = NULL;

	Handle -> TIMER[0] = NULL;
	Handle -> TIMER[1] = NULL;
	Handle -> TIMER[2] = NULL;

	Handle -> SONG = NULL;
	Handle -> FONT = NULL;

	return Handle;
}


// internal
void title_page (ALLEGRO_TIMER* TIMER[3], ALLEGRO_EVENT_QUEUE* EVENT_QUEUE, int* WINDOW);



// interface
void game_init (handle*);
void game_begin (handle*);
int game_run (handle*);
void game_destroy (handle*);

