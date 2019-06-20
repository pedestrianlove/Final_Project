#include "internal-event.h"

int process_event(){
	// Request the event
	ALLEGRO_EVENT event;
	al_wait_for_event(event_queue, &event);

	// Our setting for controlling animation
	if(event.timer.source == timer){
		if(character2.x < -150) dir = false;
		else if(character2.x > WIDTH+50) dir = true;

		if(dir) character2.x -= 10;
		else character2.x += 10;
	}
    	if(event.timer.source == timer2){
        	ture = false;
        	next = true;
    	}
    	if(event.timer.source == timer3){
        	if(next) next = false;
        	else ture = true;
    	}

    	// Keyboard
    	if(event.type == ALLEGRO_EVENT_KEY_UP)
    	{
        	switch(event.keyboard.keycode)
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
	
