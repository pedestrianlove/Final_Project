#include "internal-object.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>


typedef struct stage {
	int index;
	int WIDTH, HEIGHT;
	ALLEGRO_SAMPLE* BGM;
	ALLEGRO_SAMPLE_INSTANCE* BGM_INSTANCE;

	object* BACKGROUND;
	int OBJECT_NUMBER;
	circle** OBJECTS;
}stage;



//internal
char* find_stage_path (int);
circle** load_objects (FILE*, int);
object* load_background (char*);
ALLEGRO_SAMPLE* load_music (char*);

// interface
void restore_stage (stage*);
stage* load_stage (int, ALLEGRO_DISPLAY*);
void destroy_stage (stage*);
stage* init_stage (int);
