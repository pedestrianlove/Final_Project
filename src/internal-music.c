#include "internal-music.h"


ALLEGRO_SAMPLE_INSTANCE* start_bgm_instance (ALLEGRO_SAMPLE* song)
{
	ALLEGRO_SAMPLE_INSTANCE* sampleInstance = al_create_sample_instance (song);
	al_attach_sample_instance_to_mixer(sampleInstance, al_get_default_mixer());
	al_play_sample_instance(sampleInstance);
	return sampleInstance;
}


void raise_volume (ALLEGRO_SAMPLE_INSTANCE* BGM)
{
	if (BGM == NULL)
		printf ("This sample instance no longer exists\n");
	else
		al_set_sample_instance_gain (BGM, al_get_sample_instance_gain (BGM) + 0.05);
}


void decrease_volume (ALLEGRO_SAMPLE_INSTANCE* BGM)
{
	if (BGM == NULL)
		printf ("This sample instance no longer exists\n");
	else
		al_set_sample_instance_gain (BGM, al_get_sample_instance_gain (BGM) - 0.05);
}


void play_sample_instance (ALLEGRO_SAMPLE_INSTANCE* BGM)
{
	al_play_sample_instance (BGM);
}


void stop_sample_instance (ALLEGRO_SAMPLE_INSTANCE* BGM)
{
	al_stop_sample_instance (BGM);
}
