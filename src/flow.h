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
typedef struct point {
	int x;
	int y;
}point;


typedef struct object {
	ALLEGRO_BITMAP* AVATAR;
	point POSITION;
	int HP;
}object;


typedef struct handle {
	char* TITLE;
	int FPS;
	int WIDTH, HEIGHT;

	ALLEGRO_BITMAP* IMAGE;
	ALLEGRO_BITMAP* IMAGE2;
	ALLEGRO_BITMAP* IMAGE3;
	ALLEGRO_BITMAP *BG;
	
	ALLEGRO_KEYBOARD_STATE KEY_STATE ;
	ALLEGRO_DISPLAY* DISPLAY;
	ALLEGRO_EVENT_QUEUE* EVENT_QUEUE;
	
	ALLEGRO_SAMPLE* SONG;
	ALLEGRO_FONT* FONT;
	
	ALLEGRO_TIMER* TIMER;
	ALLEGRO_TIMER* TIMER2;
	ALLEGRO_TIMER* TIMER3;
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

	Handle -> TIMER = NULL;
	Handle -> TIMER2 = NULL;
	Handle -> TIMER3 = NULL;

	Handle -> SONG = NULL;
	Handle -> FONT = NULL;

	return Handle;
}


// internal


// interface
void game_init (handle*);
void game_begin (handle*);
int game_run (handle*);
void game_destroy (handle*);

