#include "internal-object.h"

object* init_object (object_type type, point start, point end,  char* image_path, int color)
{
	object* new_object = malloc (sizeof(object));
	
	new_object -> TYPE = type;
	new_object -> start = start;
	
	if (new_object->TYPE != AL_OBJECT) {
		new_object -> PIC = al_load_bitmap (image_path);
		if (new_object -> PIC == NULL) {
			free (new_object);
			return NULL;
		}
	}
	else {
		new_object -> end = end;
		new_object -> color = COLOR (color);
	}

	return new_object;
}

circle* init_circle (point center, double radius)
{
	circle* new_circle = malloc (sizeof(circle));

	new_circle -> x = center.x;
	new_circle -> y = center.y;
	new_circle -> radius = radius;

	return new_circle;
}

void draw_object (object* obj)
{
	if (obj == NULL) {
		printf("This object no longer exists.\n");
		return;
	}

	if (obj->TYPE != AL_OBJECT) {
		al_draw_bitmap (obj->PIC, obj->start.x, obj->start.y, 0);	
	}
	else {
		al_draw_rectangle(obj->start.x, obj->start.y, obj->end.x, obj->end.y, obj->color, 0);
	}

}

void draw_circle (circle* obj)
{
	if (obj != NULL)
		al_draw_filled_circle (obj -> x, obj->y, obj->radius, COLOR (GREY));
}

void move_object (circle* obj)
{
	obj->x += obj->velocity.x;
	obj->y += obj->velocity.y;
}


void destroy_circles (circle* obj)
{
	free (obj);
}

void destroy_object (object* obj)
{
	al_unlock_bitmap (obj -> PIC);
	al_destroy_bitmap (obj -> PIC);
	free (obj);
}



void refresh_display ()
{
	al_flip_display ();
	clear_to_color (BLACK);
}


void clear_to_color (color COLOR)
{
	switch (COLOR) {
		case BLACK:
			al_clear_to_color (al_map_rgb (0, 0, 0));
			break;
		case WHITE:
			al_clear_to_color (al_map_rgb (255, 255, 255));
			break;
		case GREY:
			al_clear_to_color (al_map_rgb (100, 100, 100));
			break;
		case YELLOW:
			al_clear_to_color (al_map_rgb (232, 186, 70));
			break;
		default:
			printf("Unknown color, I'm not drawing it.\n");
			break;


	}

}


ALLEGRO_COLOR COLOR (color COLORS)
{
	switch (COLORS) {
		case BLACK:
			return al_map_rgb (0, 0, 0);
			break;
		case WHITE:
			return al_map_rgb (255, 255, 255);
			break;
		case GREY:
			return al_map_rgb (100, 100, 100);
			break;
		case YELLOW:
			return al_map_rgb (232, 186, 70);
			break;
		case RED:
			return al_map_rgb (232, 0, 70);
			break;
		default:
			printf("Unknown color, I'm not drawing it.\n");
			return COLOR (BLACK);
			break;


	}
}
