#include "internal-error.h"

void exception (ERROR error, handle* GAME)
{
	switch (error) {
		case ERROR_INIT_SYSTEM:
			fprintf (stderr, "Failed to init system!\n");
			destroy_handle (GAME);
			break;
		case ERROR_INIT_AUDIO:
			fprintf (stderr, "Failed to init audio!\n");
			destroy_handle (GAME);
			break;
		case ERROR_INIT_DISPLAY:
			fprintf (stderr, "Failed to init display!\n");
			destroy_handle (GAME);
			break;
		case ERROR_INIT_KEYBOARD:
			fprintf (stderr, "Failed to init keyboard!\n");
			destroy_handle (GAME);
			break;
		case ERROR_INIT_FONT:
			fprintf (stderr, "Failed to init font!\n");
			destroy_handle (GAME);
			break;
		case ERROR_INIT_IMAGE:
			fprintf (stderr, "Failed to init image!\n");
			destroy_handle (GAME);
			break;

		case ERROR_LOAD_AUDIO:
			fprintf (stderr, "Failed to load audio!\n");
			destroy_handle (GAME);
			break;
	}

	exit (9);
}


handle* init_handle ()
{
	handle* GAME = malloc (sizeof(handle));
	GAME -> TITLE = "Reddie's Adventure";
	GAME -> WIDTH = 1024;
	GAME -> HEIGHT = 768;
	GAME -> CONTINUE = 1;
	GAME -> PAGE = 0;
	GAME -> FPS = 60;
	GAME -> EVENT_QUEUE = NULL;
	GAME -> DISPLAY = NULL;

	return GAME;
}


void destroy_handle (handle* GAME)
{
	al_destroy_event_queue (GAME->EVENT_QUEUE);
	al_destroy_display (GAME->DISPLAY);

	free (GAME);
	GAME = NULL;
	al_uninstall_system ();
}

void check_pointer (void* ptr)
{
	assert (ptr != NULL);
}
