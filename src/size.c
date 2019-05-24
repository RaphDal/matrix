#include "private.h"

matrix_t *matrix_size(matrix_t *matrix)
{
    matrix_t *res;

    if (!matrix)
        return (error_ptr(ERROR_NULL_PARAMETER));
    if (!(res = custom(1, 2, 0)))
        return (NULL);
    res->matrix[0][0] = matrix->rows;
    res->matrix[0][1] = matrix->cols;
    return (res);
}