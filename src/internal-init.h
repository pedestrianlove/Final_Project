#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>


// internal




// interface
void init_audio ();
void init_display (int, int, char*, ALLEGRO_EVENT_QUEUE*, ALLEGRO_DISPLAY*);
void init_keyboard (ALLEGRO_EVENT_QUEUE* EVENT_QUEUE);

void exception (int, char* str);
