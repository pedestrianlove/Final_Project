#include "internal-error.h"

void show_err_msg (char* msg_str) {
    fprintf(stderr, "unexpected msg: %s\n", msg_str);
    exit(9);
}

