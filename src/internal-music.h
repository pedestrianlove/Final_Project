#include <stdio.h>

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>



ALLEGRO_SAMPLE_INSTANCE* start_bgm_instance (ALLEGRO_SAMPLE*);
void raise_volume (ALLEGRO_SAMPLE_INSTANCE*);
void decrease_volume (ALLEGRO_SAMPLE_INSTANCE*);
void start_sample_instance (ALLEGRO_SAMPLE_INSTANCE*);
void stop_sample_instance (ALLEGRO_SAMPLE_INSTANCE*);
