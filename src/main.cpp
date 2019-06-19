#include <stdio.h>
#include <allegro5/allegro.h>
#include "music.h"

int real_main (int argc, char **argv)
{
	HELLO ();



	return 0;
}



int main(int argc, char **argv)
{
	return al_run_main(argc, argv, real_main);
}
