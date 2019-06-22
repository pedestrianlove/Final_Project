#include "internal-event.h"

int process_event (ALLEGRO_EVENT_QUEUE* EVENT_QUEUE){
	// Request the event
	ALLEGRO_EVENT* event = malloc (sizeof(ALLEGRO_EVENT));
	al_wait_for_event (EVENT_QUEUE, event);

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
    	else if(event->type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        	return GAME_TERMINATE;

	return 0;
}
	
