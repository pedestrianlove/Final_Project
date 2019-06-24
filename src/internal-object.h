#include <stdio.h>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

typedef enum color {
	BLACK,
	WHITE,
	GREY,
	YELLOW,
	RED
}color;

typedef enum object_type{
	AL_BACKGROUND,
	AL_CHARACTER,
	AL_OBJECT
}object_type;

typedef struct point {
	int x, y;
}point;


typedef struct object {
	ALLEGRO_BITMAP* PIC;
	ALLEGRO_COLOR color;
	point start;
	point end;
	int TYPE;
}object;

object* init_object (object_type type, point start, point end, char* image_path, int color);
void draw_object (object*);
void destroy_object (object*);

void refresh_display ();
void clear_to_color (color);
ALLEGRO_COLOR COLOR (color);
