#include "page.h"
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
	// REQUIRES A START BUTTON FIXME
	refresh_display ();
	
	return title_event_handler (GAME->event_queue, GAME->display);
}


int about_page (control* GAME)
{
	// show details of development and my number FIXME
	return settings_page;
}


int game_page (control* GAME)
{
	// requires a external function to load stage FIXME
	// itself should process the movement of Reddie
	point position = {0,0};
	object* BACKGROUND = init_object (AL_BACKGROUND, position, "res/images/stage1.jpeg");
	draw_object (BACKGROUND);
	refresh_display ();

	return EXIT_PAGE;
}


int settings_page (control* GAME) // help_page is integrated into this page
{
	// adjust volume or some other settings (if available) FIXME
	
	return EXIT_PAGE;
}


int exit_page (control* GAME)
{
	// ask are you sure you want to quit? FIXME
	return EXIT_PAGE;
}

