#include "private.h"

bool matrix_is_squared(matrix_t *a)
{
    if (!a)
        return (false);
    return (a->rows == a->cols);
}

bool matrix_is_multiplicable(matrix_t *a, matrix_t *b)
{
    if (!a || !b)
        return (false);
    return (a->cols == b->rows);
}