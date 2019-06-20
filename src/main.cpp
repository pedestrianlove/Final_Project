#include "flow.h"

int main (int argc, char **argv)
{
	init_handle* GAME = (init_handle*) malloc (sizeof(init_handle));
	game_init (GAME);

	game_begin (GAME);

	game_destroy ();

	return 0;
}

