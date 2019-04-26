#include "private.h"

static void print_error(char const *msg)
{
    if (disperror)
        fprintf(stderr, "matrix: %s.\n", msg);
}

void *error_ptr(char const *msg)
{
    print_error(msg);
    return (NULL);
}

int error_int(char const *msg)
{
    print_error(msg);
    return (-1);
}

bool error_bool(char const *msg)
{
    print_error(msg);
    return (false);
}