#include "private.h"

static void print_error(char const *msg)
{
    fprintf(stderr, "matrix: %s\n", msg);
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

void *error_malloc(void)
{
    print_error("Not enough memory to malloc");
}