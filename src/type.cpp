#include "type.h"

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



