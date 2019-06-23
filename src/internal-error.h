#include <stdio.h>
#include <assert.h>

#include <allegro5/allegro.h>

typedef enum ERROR {
	ERROR_INIT_SYSTEM,
	ERROR_INIT_AUDIO,
	ERROR_INIT_DISPLAY,
	ERROR_INIT_KEYBOARD,
	ERROR_INIT_FONT,
	ERROR_INIT_IMAGE,

	ERROR_LOAD_AUDIO
}ERROR;

typedef struct handle {
	char* TITLE;
	int WIDTH, HEIGHT;
	int PAGE;
	float  FPS;
	int CONTINUE;


	ALLEGRO_EVENT_QUEUE* EVENT_QUEUE;
	ALLEGRO_DISPLAY* DISPLAY;

}handle;


void exception (ERROR, handle*);
handle* init_handle ();
void destroy_handle (handle*);

void check_pointer (void*);
