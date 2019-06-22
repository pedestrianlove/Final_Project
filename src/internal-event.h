#include <allegro5/allegro.h>
#define GAME_TERMINATE -1

// internal
int keyboard_events (ALLEGRO_EVENT*);
void timers_events (ALLEGRO_EVENT*);

// interface
int process_event (ALLEGRO_EVENT_QUEUE* EVENT_QUEUE);

