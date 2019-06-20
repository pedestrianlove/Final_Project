#include "flow.h"
#include "internal-error.h"

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


void game_init(handle* GAME) {
	exception (al_init(), "Initialization failed.", GAME);
	exception (al_install_audio(), "Failed to initialize audio!", GAME);
	exception (al_init_acodec_addon(), "ailed to initialize audio codecs!", GAME);
	exception (al_reserve_samples(1), "Failed to reserve samples!", GAME);
    	// Create display
    	GAME -> DISPLAY = al_create_display(GAME->WIDTH, GAME->HEIGHT);
    	GAME -> EVENT_QUEUE = al_create_event_queue();
    	exception (GAME->DISPLAY != NULL && GAME->EVENT_QUEUE != NULL, 
			"Failed to initialize the display!", GAME);  

    	// Initialize Allegro settings
    	al_set_window_position(GAME->DISPLAY, 0, 0);
    	al_set_window_title(GAME->DISPLAY, GAME->TITLE);
    	al_init_primitives_addon();
    	al_install_keyboard();
    	al_install_audio();
    	al_init_image_addon();
    	al_init_acodec_addon();
    	al_init_font_addon();
    	al_init_ttf_addon();

    	// Register event
	al_register_event_source(GAME->EVENT_QUEUE, al_get_display_event_source(GAME->DISPLAY));
	al_register_event_source(GAME->EVENT_QUEUE, al_get_keyboard_event_source());
}


void game_begin(handle* GAME) {
	GAME -> SONG = al_load_sample("res/sounds/hello.wav");
    	exception (GAME->SONG != NULL, "Audio clip sample not loaded!", GAME);
	al_play_sample(GAME->SONG, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
    
    	al_clear_to_color(al_map_rgb(100, 100, 100));
    
    	GAME -> FONT = al_load_ttf_font("res/fonts/pirulen.ttf",14,0);
    	int text_width = GAME -> WIDTH /2;
	int text_height = GAME -> HEIGHT/2 + 220;

	al_draw_text(GAME->FONT, al_map_rgb(255,255,255), text_width, text_height, ALLEGRO_ALIGN_CENTRE, "Press 'Enter' to start"); 
	al_draw_rectangle(text_width-150, 510, text_width+150, 550, al_map_rgb(255, 255, 255), 0);
    
	al_flip_display();
	sleep (5000);
}


void game_destroy (handle* GAME)
{
	// Make sure you destroy all things
	al_destroy_event_queue(GAME -> EVENT_QUEUE);
	al_destroy_display(GAME -> DISPLAY);
	al_destroy_timer(GAME -> TIMER);
	al_destroy_timer(GAME -> TIMER2);
	al_destroy_bitmap(GAME -> IMAGE);
	al_destroy_sample(GAME -> SONG);
}

void exception (int val, char* str, handle* GAME)
{
	if (!val) {
		show_err_msg("Initialization failed.");
		game_destroy (GAME);
	}
}
