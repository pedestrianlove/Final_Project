#include "flow.h"
#include "internal-event.h"
#include "internal-init.h"
#include "internal-load.h"


void game_init(handle* GAME) {
	init_allegro_system ();	
	init_audio ();
	init_display (GAME->WIDTH, GAME->HEIGHT, GAME->TITLE
			GAME->EVENT_QUEUE, GAME->DISPLAY); 
	init_keyboard (GAME->EVENT_QUEUE);

       	al_init_image_addon();
    	al_init_font_addon();
    	al_init_ttf_addon();

    	// Register event
}



void game_begin(handle* GAME) {
	load_song (GAME->SONG, "res/sounds/hello.wav");    
    	load_text (GAME->FONT, GAME->WIDTH, GAME->HEIGHT);    
	al_flip_display();
}


int game_run(handle* GAME) {
    	int error = 0;
    	// First window(Menu)
	if(window == 1){
		if (!al_is_event_queue_empty(GAME->EVENT_QUEUE)) {
            		error = process_event(GAME->EVENT_QUEUE);
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



void game_destroy (handle* GAME) {
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




