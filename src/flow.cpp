#include "flow.h"
#include "internal-error.h"

void game_init(handle* GAME) {
	exception (al_init(), 
			"Initialization failed.", GAME);
	exception (al_install_audio(), 
			"Failed to initialize audio!", GAME);
	exception (al_init_acodec_addon(), 
			"Failed to initialize audio codecs!", GAME);
	exception (al_reserve_samples(1), 
			"Failed to reserve samples!", GAME);
    	
	// Create display
    	GAME -> DISPLAY = al_create_display(GAME->WIDTH, GAME->HEIGHT);
    	GAME -> EVENT_QUEUE = al_create_event_queue();
    	exception (GAME->DISPLAY != NULL && GAME->EVENT_QUEUE != NULL, 
			"Failed to initialize the display!", GAME);  

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

	al_draw_text(GAME->FONT, 
			al_map_rgb(255,255,255), text_width, text_height, 
			ALLEGRO_ALIGN_CENTRE, "Press 'Enter' to start"); 
	al_draw_rectangle(text_width-150, 510, text_width+150, 550, 
			al_map_rgb(255, 255, 255), 0);
    
	al_flip_display();
}


int game_run() {
    	int error = 0;
    	// First window(Menu)
	if(window == 1){
		if (!al_is_event_queue_empty(event_queue)) {
            		error = process_event();
            		if(judge_next_window) {
               			window = 2;
                		// Setting Character
                		character1.x = WIDTH / 2;
                		character1.y = HEIGHT / 2 + 150;
                		character2.x = WIDTH + 100;
                		character2.y = HEIGHT / 2 - 280;
                		character1.image_path = al_load_bitmap("res/images/tower.png");
                		character2.image_path = al_load_bitmap("res/images/teemo_left.png");
                		character3.image_path = al_load_bitmap("res/images/teemo_right.png");
                		background = al_load_bitmap("res/images/stage.jpg");
	
                		//Initialize Timer
                		timer  = al_create_timer(1.0/15.0);
                		timer2  = al_create_timer(1.0);
                		timer3  = al_create_timer(1.0/10.0);
                		al_register_event_source(event_queue, al_get_timer_event_source(timer)) ;
                		al_register_event_source(event_queue, al_get_timer_event_source(timer2)) ;
                		al_register_event_source(event_queue, al_get_timer_event_source(timer3)) ;
                		al_start_timer(timer);
                		al_start_timer(timer2);
                		al_start_timer(timer3);
            		}
        	}
    	}
    	// Second window(Main Game)
    	else if(window == 2){
        	// Change Image for animation
        	al_draw_bitmap(background, 0,0, 0);
        	if(ture) al_draw_bitmap(character1.image_path, character1.x, character1.y, 0);

        	if(dir) al_draw_bitmap(character2.image_path, character2.x, character2.y, 0);
        	else al_draw_bitmap(character3.image_path, character2.x, character2.y, 0);

        	al_flip_display();
        	al_clear_to_color(al_map_rgb(0,0,0));

        	// Listening for new event
        	if (!al_is_event_queue_empty(event_queue)) {
        		error = process_event();
        	}
    	}
    	return error;
}


void game_destroy (handle* GAME)
{
	// Make sure you destroy all things
	al_destroy_event_queue (GAME -> EVENT_QUEUE);
	al_destroy_display (GAME -> DISPLAY);
	al_destroy_timer (GAME -> TIMER);
	al_destroy_timer (GAME -> TIMER2);
	al_destroy_timer (GAME -> TIMER3);
	al_destroy_bitmap (GAME -> IMAGE);
	al_destroy_sample (GAME -> SONG);

	free (GAME);
}

void exception (int val, char* str, handle* GAME)
{
	if (!val) {
		show_err_msg("Initialization failed.");
		game_destroy (GAME);
	}
}
