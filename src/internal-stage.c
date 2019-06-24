#include "internal-stage.h"


stage* load_stage (int number)
{
	stage* new_stage = init_stage (number);	

	draw_object (new_stage -> BACKGROUND);
	for (int i = 0; i < number; i++)
		draw_object (new_stage -> OBJECTS[i]);
	return new_stage;
}


stage* init_stage (int index) {
	stage* new_stage = malloc (sizeof(stage));
	new_stage -> index = index;
	
	char input_tmp [100];
	char BACKGROUND_PATH[100], BGM_PATH[100];
	char* stage_path = find_stage_path (index);
	FILE* file = fopen (stage_path, "r");
	if (file != NULL) {
		fscanf (file, "%s%s", input_tmp, BACKGROUND_PATH);
		new_stage -> BACKGROUND = load_background (BACKGROUND_PATH);
		
		fscanf (file, "%s%s", input_tmp, BGM_PATH);
		new_stage -> BGM = load_music (BGM_PATH);

		fscanf (file, "%s%d", input_tmp, &(new_stage->OBJECT_NUMBER));
		new_stage -> OBJECTS = load_objects (file, new_stage->OBJECT_NUMBER);

	}
	else {
		printf("Unknown stage file is specified.\n");
		free (new_stage);
		new_stage = NULL;
	}
	fclose (file);	
	
	new_stage -> WIDTH = al_get_bitmap_width (new_stage->BACKGROUND->PIC);
	new_stage -> HEIGHT = al_get_bitmap_height (new_stage->BACKGROUND->PIC);
	
	return new_stage;
}
object** load_objects (FILE* file, int number)
{
	object** LIST = malloc (sizeof(object*) * number);
	
	point start_pos, end_pos;
	char input_tmp[100];
	for (int i = 0; i < number; i++) {	
		fscanf (file, "%s%s%d%d", input_tmp, input_tmp, &(start_pos.x), &(start_pos.y));
		fscanf (file, "%s%d%d", input_tmp, &(end_pos.x), &(end_pos.y));
		LIST[i] = init_object (AL_OBJECT, start_pos, end_pos, NULL, BLACK);
	}

	return LIST;
}
object* load_background (char* bg_path)
{
	point position = {0, 0};
	object* new_bg = init_object (AL_BACKGROUND, position, position, bg_path, BLACK); 
	return new_bg;
}
ALLEGRO_SAMPLE* load_music (char* bgm_path)
{
	ALLEGRO_SAMPLE* song = al_load_sample (bgm_path);
    	if (!song){
        	printf( "Audio clip sample not loaded!\n" );
        	return NULL;
    	}
    	// This should be implemented in another file!FIXME
	al_play_sample(song, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);

	return song;
}

char* find_stage_path (int index)
{
	char* FINAL_PATH = malloc (sizeof(char) * 100);
	
	char* STATIC_PATH = "res/stages/";
	char VAR_PATH[10];
	sprintf(VAR_PATH, "%d", index);

	sprintf(FINAL_PATH, "%s%s", STATIC_PATH, VAR_PATH);
	
	return FINAL_PATH;
}

void destroy_stage (stage* STAGE)
{
	al_stop_samples ();
	destroy_object (STAGE -> BACKGROUND);
	for (int i = 0; i < STAGE -> OBJECT_NUMBER; i++)
		destroy_object (STAGE->OBJECTS[i]);
}
