#include "flow.h"
#include "internal_error.h"

void game_init(init_handle* Handle) {
    	if (!al_init()) 
        	show_err_msg("Initialization failed.");
    	if(!al_install_audio())
		show_err_msg("Failed to initialize audio!");
    	if(!al_init_acodec_addon())
     		show_err_msg("Failed to initialize audio codecs!");
    	if (!al_reserve_samples(1))
		show_err_msg("Failed to reserve samples!");

    	// Create display
    	Handle -> DISPLAY = al_create_display(Handle->WIDTH, Handle->HEIGHT);
    	Handle -> EVENT_QUEUE = al_create_event_queue();
    	if (Handle->DISPLAY == NULL || Handle->EVENT_QUEUE == NULL) {
     	   show_err_msg("Failed to initialize the display!");
    	}

    	// Initialize Allegro settings
    	al_set_window_position(Handle->DISPLAY, 0, 0);
    	al_set_window_title(Handle->DISPLAY, Handle->TITLE);
    	al_init_primitives_addon();
    	al_install_keyboard();
    	al_install_audio();
    	al_init_image_addon();
    	al_init_acodec_addon();
    	al_init_font_addon();
    	al_init_ttf_addon();

    	// Register event
	al_register_event_source(Handle->EVENT_QUEUE, al_get_display_event_source(Handle->DISPLAY));
	al_register_event_source(Handle->EVENT_QUEUE, al_get_keyboard_event_source());
}


void game_begin(init_handle* Handle) {
    	if (!al_load_sample("res/sounds/hello.wav"))
        	show_err_msg("Audio clip sample not loaded!"); 
    
    	al_play_sample(SONG_NORMAL, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
    
    	al_clear_to_color(al_map_rgb(100, 100, 100));
    
    	Handle -> FONT = al_load_ttf_font("res/fonts/pirulen.ttf",14,0);

    	int text_width = Handle -> WIDTH /2;
	int text_height = Handle -> HEIGHT/2 + 220;
	al_draw_text(Handle->FONT, al_map_rgb(255,255,255), text_width, text_height, ALLEGRO_ALIGN_CENTRE, "Press 'Enter' to start"); 
	al_draw_rectangle(text_width-150, 510, text_width+150, 550, al_map_rgb(255, 255, 255), 0);
    
	al_flip_display();
}


void game_destroy ()
{

}
