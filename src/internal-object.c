#include "internal-object.h"

object* init_object (object_type type, point position,  char* image_path)
{
	object* new_object = malloc (sizeof(object));
	
	new_object -> TYPE = type;
	new_object -> POSITION = position;
	
	new_object -> PIC = al_load_bitmap (image_path);
	if (new_object -> PIC == NULL) {
		free (new_object);
		return NULL;
	}

	return new_object;
}

void draw_object (object* obj)
{
	al_draw_bitmap (obj->PIC, obj->POSITION.x, obj->POSITION.y, 0);	
}


void destroy_object (object* obj)
{
	al_destroy_bitmap (obj -> PIC);
	free (obj);
}



void refresh_display ()
{
	al_flip_display ();

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
