#include "internal_error.h"
#include "flow.h"

void show_err_msg (char* msg_str) {
    fprintf(stderr, "unexpected msg: %s\n", msg_str);
    game_destroy();
    exit(9);
}

