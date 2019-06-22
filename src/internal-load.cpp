#include "internal-load.h"
#include "internal-error.h"

void load_song (ALLEGRO_SAMPLE* SONG, char* song_path)
{
	SONG = al_load_sample(song_path);
    	exception (SONG != NULL, "Audio clip sample not loaded!");
	al_play_sample(SONG, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);

}
void load_text (ALLEGRO_FONT* FONT, int WIDTH, int HEIGHT)
{
	al_clear_to_color(al_map_rgb(100, 100, 100)); 
    	FONT = al_load_ttf_font("res/fonts/pirulen.ttf",14,0);
    	int text_width = WIDTH /2;
	int text_height = HEIGHT/2 + 220;

	al_draw_text(FONT, 
			al_map_rgb(255,255,255), text_width, text_height, 
			ALLEGRO_ALIGN_CENTRE, "Press 'Enter' to start"); 
	al_draw_rectangle(text_width-150, 510, text_width+150, 550, 
			al_map_rgb(255, 255, 255), 0);

}

