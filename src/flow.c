#include "flow.h"
#include "page.h"
#include "internal-init.h"

void game_init (handle* GAME)
{
	if (!init_system ())
		exception (ERROR_INIT_SYSTEM, GAME);

	
	dim dimension = {GAME->WIDTH, GAME->HEIGHT};
	if (!init_display (&(GAME->EVENT_QUEUE), &(GAME->DISPLAY), dimension, GAME->TITLE)) 
		exception (ERROR_INIT_DISPLAY, GAME);
	if (!init_keyboard (&(GAME->EVENT_QUEUE)))
		exception (ERROR_INIT_KEYBOARD, GAME);
	

	if (!init_audio ())
		exception (ERROR_INIT_AUDIO, GAME);
	if (!init_font ())
		exception (ERROR_INIT_FONT, GAME);
	if (!init_image ())
		exception (ERROR_INIT_IMAGE, GAME);
}


void game_run (handle* GAME)
{
	int PAGE_TMP;
	control* controller = init_control (GAME->EVENT_QUEUE, GAME->DISPLAY);	
	while (GAME->CONTINUE) {
		if (GAME->PAGE != EXIT_PAGE) 
			PAGE_TMP = GAME->PAGE;

		switch (GAME->PAGE) {
			case TITLE_PAGE:
				GAME -> PAGE = title_page (controller);
				break;
			case ABOUT_PAGE:
				GAME -> PAGE = about_page (controller);
				break;
			case HELP_PAGE:
				GAME -> PAGE = help_page (controller);
				break;
			case GAME_PAGE:
				GAME -> PAGE = game_page (controller);
				break;
			case SETTINGS_PAGE:
				GAME -> PAGE = settings_page (controller);
				break;
			case EXIT_PAGE:
				GAME -> PAGE = game_page (controller);
				if (GAME->PAGE != EXIT_PAGE) {
					GAME->PAGE = PAGE_TMP;
					break;
				}
				GAME->CONTINUE = 0;
				break;
			default:
				printf("The specified page is unknown.\n");
				GAME->CONTINUE = 0;
				break;
		}
	}
	free (controller);
}


void game_end (handle* GAME)
{
	destroy_handle (GAME);
}


