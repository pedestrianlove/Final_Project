#include "page.h"
#include "internal-stage.h"

control* init_control (ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_DISPLAY* display)
{
	control* ctrl = malloc (sizeof(control));
	ctrl -> event_queue = event_queue;
	ctrl -> display = display;
	ctrl -> game_state = malloc (sizeof(ALLEGRO_STATE));
	ctrl -> end_state = malloc (sizeof(ALLEGRO_STATE));

	return ctrl;
}


int intro_page (control* GAME)
{
	clear_to_color (YELLOW);
	ALLEGRO_FONT* font;
	font = al_load_ttf_font ("res/fonts/gravitas-cufonfonts/Gravitas_Light_Italic.otf", 72, 0);
	al_draw_text (font, COLOR (RED),
			412, 300, ALLEGRO_ALIGN_CENTRE, "Reddie's has been trapped,");
	al_draw_text (font, COLOR (RED),
			550, 400, ALLEGRO_ALIGN_CENTRE, "can you help it to find its home?");

	refresh_display ();

	al_rest (5);

	return GAME_PAGE;
}

int title_page (control* GAME)
{
	ALLEGRO_FONT* font;

	int WIDTH = al_get_display_width (GAME->display);
	int HEIGHT = al_get_display_height (GAME->display);
	clear_to_color (YELLOW);
    	
	// TITLE
	font = al_load_ttf_font("res/fonts/gravitas-cufonfonts/Gravitas_Bold_Italic.otf",100 ,0);
    	al_draw_text(font, COLOR (RED), 
			WIDTH/2, HEIGHT/2-300 , ALLEGRO_ALIGN_CENTRE, "Reddie's Adventure.");
	
	
	// BUTTONS
	region** button_list = malloc (sizeof(region*) * 3);
	for (int i = 0; i < 3; i++)
		button_list[i] = NULL;
	font = al_load_ttf_font ("res/fonts/gravitas-cufonfonts/Gravitas_Light_Italic.otf", 100, 0);
	int spacing = 100, spacing1 = 150;
	
	al_draw_text(font, COLOR (RED), 500, 280, ALLEGRO_ALIGN_CENTRE, "START");
	button_list[0] = create_button (500-spacing, 280, 500+spacing, 280+spacing);
	
	al_draw_text(font, COLOR (RED), 500, 430 , ALLEGRO_ALIGN_CENTRE, "ABOUT");
	button_list[1] = create_button (500-spacing, 280+spacing1, 500+spacing, 280+spacing+spacing1);

	al_draw_text(font, COLOR (RED), 500, 580 , ALLEGRO_ALIGN_CENTRE, "EXIT");
	button_list[2] = create_button (500-spacing, 280+spacing1*2, 500+spacing, 280+spacing+spacing1*2);


	refresh_display ();
	
	int PAGE = title_event_handler (GAME->event_queue, GAME->display, button_list, 3);
	while (PAGE == TITLE_PAGE)
		PAGE = title_event_handler (GAME->event_queue, GAME->display, button_list, 3);
	
	return PAGE;
}

 
int about_page (control* GAME)
{
    	clear_to_color (YELLOW);
	ALLEGRO_FONT* font = al_load_ttf_font("res/fonts/gravitas-cufonfonts/Gravitas_Light_Italic.otf",60,0);
	al_draw_text (font, COLOR (RED), 
		350, 250 , ALLEGRO_ALIGN_CENTRE, "Reddie's Adventure,");
	al_draw_text (font, COLOR (RED), 550, 400, ALLEGRO_ALIGN_CENTRE, "developed by JHIH-SIOU LI, 105021226");
	refresh_display ();
	int PAGE = about_event_handler (GAME->event_queue, GAME->display);
	while (PAGE == ABOUT_PAGE)
		PAGE = about_event_handler (GAME->event_queue, GAME->display);
	return PAGE;
}


int game_page (control* GAME)
{
	stage* current_stage = load_stage (0, GAME->display);
	al_store_state(GAME->game_state, ALLEGRO_STATE_ALL);
	
	circle* Reddie = malloc (sizeof(circle));
	Reddie -> x = 50;
	Reddie -> y = 50;
	Reddie -> radius = 20;
	al_draw_filled_circle (Reddie->x, Reddie->y, Reddie->radius, COLOR(RED));
	

	int CONTINUE = 1;
	while (CONTINUE) {
		al_draw_filled_circle (Reddie->x, Reddie->y, Reddie->radius, COLOR(RED));
		refresh_display ();
		switch (game_event_handler (GAME->event_queue, GAME->display)) {
			
		}
	}

	
	refresh_display ();
	//destroy_stage (current_stage);
	return EXIT_PAGE;
}


int settings_page (control* GAME)
{
#warning TODO: adjust volume or some other settings (if available)
	
	return EXIT_PAGE;
}


int exit_page (control* GAME)
{
	al_store_state (GAME->end_state, ALLEGRO_STATE_ALL);
	
	al_resize_display (GAME->display, 1024, 768);	
	int WIDTH = al_get_display_width (GAME->display);
	int HEIGHT = al_get_display_height (GAME->display);
	int SHIFT = 500;
	clear_to_color (YELLOW);

	ALLEGRO_FONT* font = al_load_ttf_font("res/fonts/gravitas-cufonfonts/Gravitas_Bold_Italic.otf",72,0);
    	al_draw_text(font, COLOR (RED), 
			WIDTH/2, HEIGHT/2+280-SHIFT , ALLEGRO_ALIGN_CENTRE, "Are you sure you want to quit?");
	al_draw_text (font, COLOR (RED), WIDTH/2, HEIGHT/2+560-SHIFT, ALLEGRO_ALIGN_CENTRE, "Any unsaved progess will be lost.");
	
	region** button_list = malloc (sizeof(region*) * 2);
	for (int i = 0; i < 2; i++)
		button_list[i] = NULL;

	al_draw_text (font, COLOR (RED), 150, 700, ALLEGRO_ALIGN_CENTRE, "GO BACK");
	button_list[0] = create_button (60, 700, 250, 768);
	al_draw_text (font, COLOR (RED), 900, 700, ALLEGRO_ALIGN_CENTRE, "QUIT");
	button_list[1] = create_button (810, 700, 1000, 768);	
	
	al_flip_display ();

	int PAGE = exit_event_handler (GAME->event_queue, GAME->display, button_list, 2);
	while (PAGE == HALF_QUIT)
		PAGE = exit_event_handler (GAME->event_queue, GAME->display, button_list, 2);
		
	if (PAGE == EXIT_PAGE)
		return EXIT_PAGE;
	else{
		al_restore_state (GAME->end_state);
		al_flip_display ();
		return TITLE_PAGE;
	}
}

