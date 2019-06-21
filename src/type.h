#include <stdio.h>
#include <stdlib.h>

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

typedef struct ball {
	ALLEGRO_BITMAP* AVATAR;
	point POSITION;
	int HP;
}ball;

typedef struct 




typedef struct handle {
	char* TITLE;
	int FPS;
	int WIDTH, HEIGHT;

	ball Reddie;	

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
handle* Handle_init ();

