#include "private.h"

bool matrix_is_squared(matrix_t *a)
{
    if (!a)
        return (error_bool(ERROR_NULL_PARAMETER));
    return (a->rows == a->cols);
}

bool matrix_is_multiplicable(matrix_t *a, matrix_t *b)
{
    if (!a || !b)
        return (error_bool(ERROR_NULL_PARAMETER));
    return (a->cols == b->rows);
}