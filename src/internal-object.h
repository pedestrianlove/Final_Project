#include <stdio.h>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "internal-physics.h"

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
	double x, y;
}point;


typedef struct object {
	ALLEGRO_BITMAP* PIC;
	ALLEGRO_COLOR color;
	point start;
	point end;
	int TYPE;
}object;

circle* init_circle (point, double);
object* init_object (object_type type, point start, point end, char* image_path, int color);
void move_object (circle*);
void draw_object (object*);
void draw_circle (circle*);
void destroy_object (object*);
void destroy_circles (circle*);

void refresh_display ();
void clear_to_color (color);
ALLEGRO_COLOR COLOR (color);
