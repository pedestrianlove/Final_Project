#include "page.h"
#include "internal-object.h"
#include "internal-stage.h"

control* init_control (ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_DISPLAY* display)
{
	control* ctrl = malloc (sizeof(control));
	ctrl -> event_queue = event_queue;
	ctrl -> display = display;

	return ctrl;
}



int title_page (control* GAME)
{
	int WIDTH = al_get_display_width (GAME->display);
	int HEIGHT = al_get_display_height (GAME->display);
	clear_to_color (YELLOW);
    	ALLEGRO_FONT* font = al_load_ttf_font("res/fonts/gravitas-cufonfonts/Gravitas_Bold_Italic.otf",72,0);
	int SHIFT = 500;
    	al_draw_text(font, COLOR (RED), 
			WIDTH/2, HEIGHT/2+280-SHIFT , ALLEGRO_ALIGN_CENTRE, "Reddie's Adventure.");
    	al_draw_rectangle(WIDTH/2-150, HEIGHT/2+265-SHIFT, 
			WIDTH/2+150, HEIGHT/2+330-SHIFT, COLOR (RED), 0);
	
	refresh_display ();
	al_rest (30);
	return EXIT_PAGE;
}


int help_page (control* GAME)
{
	return EXIT_PAGE;
}


int about_page (control* GAME)
{
	return EXIT_PAGE;
}


int game_page (control* GAME)
{
	load_stage (0);
	point position = {0,0};
	object* BACKGROUND = init_object (AL_BACKGROUND, position, "res/images/stage1.jpeg");
	draw_object (BACKGROUND);

	return EXIT_PAGE;
}


int settings_page (control* GAME)
{

	return EXIT_PAGE;
}


int exit_page (control* GAME)
{
	return EXIT_PAGE;
}

