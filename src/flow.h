
// custom types
#include "type.h"

// internal
void init_audio (handle*);
void init_display (handle*);
void init_keyboard (handle*);


// interface
void game_init (handle*);
void game_begin (handle*);
int game_run (handle*);
void game_destroy (handle*);

void exception (int, char* str, handle*);
