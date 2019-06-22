#include "flow.h"
#include "internal-event.h"
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
		title_page (GAME->EVENT_QUEUE, &(GAME->WINDOW));	
    	}
    	// Second window(Main Game)
    	else if(window == 2){
		game_page ();
	}
    	return error;
}
void title_page (ALLEGRO_TIMER* TIMER[3], 
		ALLEGRO_EVENT_QUEUE* EVENT_QUEUE, 
		object* Reddie, int* WINDOW)
{
	if (!al_is_event_queue_empty(EVENT_QUEUE)) {
            	error = process_event(EVENT_QUEUE);
            	if(judge_next_window) {
               		*WINDOW = 2;
                	
			// Setting Character
			
			point position_ball = {WIDTH/2, HEIGHT/2 + 150};
			Reddie = init_object (3, position_ball, "res/images/red_ball.jpg");
			
			point position_object = {WIDTH+100, HEIGHT/2 - 280};
			Enemy = init_object (-1, position_object, "res/images/teemo_left.png");                	

			//Initialize Timer
                	init_timer (TIMER);            
		}
        }
}
void game_page (ALLEGRO_EVENT_QUEUE* event_queue, object* Reddie, object* Enemy)
{
	// Change Image for animation
        al_draw_bitmap(Reddie->AVATAR, Reddie->POSITION.x, Reddie->POSITION.y, 0);

        al_draw_bitmap(Enemy->AVATAR, Enemy->POSITION.x, Enemy->POSITION.y, 0);

	reset_to_black ();
	
	listen_event_queue (event_queue);
}
void listen_event_queue (ALLEGRO_EVENT_QUEUE* event_queue)
{
        // Listening for new event
        if (!al_is_event_queue_empty(event_queue)) {
        	error = process_event();
        }
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




