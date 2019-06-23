#include "flow.h"


int main (int argc, char *argv[])
{
	handle* GAME = init_handle ();

	game_init (GAME);

	game_run (GAME);

	game_end (GAME);

	return 0;
}
