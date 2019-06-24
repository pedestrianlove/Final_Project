#include "internal-object.h"

typedef struct stage {
	int index;
	object* BACKGROUND;
	
	int OBJECT_NUMBER;
	object** OBJECTS;
}stage;



//internal
char* find_stage_path (int);
object** load_objects (FILE*, int);
object* load_background (char*);

// interface
void load_stage (int);
stage* init_stage (int);
