#include "internal-event.h"

int process_event (handle* GAME){
	// Request the event
	ALLEGRO_EVENT* event = malloc (sizeof(ALLEGRO_EVENT));
	al_wait_for_event (GAME->EVENT_QUEUE, event);

	timers_events (event);	
    	if (keyboard_events (event)) { 
		free (event);
		return GAME_TERMINATE;
	}

	free (event);
	return 0;
}
void timers_events (ALLEGRO_EVENT* event)
{
	// Our setting for controlling animation
	if(event->timer.source == GAME->TIMER){
		if(character2.x < -150) dir = false;
		else if(character2.x > WIDTH+50) dir = true;

		if(dir) character2.x -= 10;
		else character2.x += 10;
	}
    	if(event->timer.source == GAME->TIMER2){
        	ture = false;
        	next = true;
    	}
    	if(event->timer.source == GAME->TIMER3){
        	if(next) next = false;
        	else ture = true;
    	}

}
int keyboard_events (ALLEGRO_EVENT* event)
{
	// Keyboard
    	if(event->type == ALLEGRO_EVENT_KEY_UP)
    	{
        	switch(event->keyboard.keycode)
        	{
			// Control
			case ALLEGRO_KEY_W:
         	       		character1.y -= 30;
     				break;
          	  	case ALLEGRO_KEY_S:
                		character1.y += 30;
                		break;
            		case ALLEGRO_KEY_A:
                		character1.x -= 30;
                		break;
            		case ALLEGRO_KEY_D:
                		character1.x += 30;
                		break;

            		// For Start Menu
            		case ALLEGRO_KEY_ENTER:
                		judge_next_window = true;
                		break;
        	}
    	}

    	// Shutdown our program
    	else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        	return GAME_TERMINATE;

	return 0;
}
	
