#include "flow.h"

int main (int argc, char **argv)
{
	handle* GAME = Handle_init ();

	game_init (GAME);
	game_begin (GAME);

	game_destroy (GAME);

	return 0;
}

