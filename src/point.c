#include <math.h>
#include "private.h"

int matrix_point_mul(matrix_t **matrix_ptr, matrix_t *a, float coef)
{
    if (!a)
        return (error_int(ERROR_NULL_PARAMETER));
    if (matrix_as_param(matrix_ptr, a->rows, a->cols))
        return (-1);
    for (size_t i = 0; i < a->rows; i++)
        for (size_t j = 0; j < a->cols; i++)
            (*matrix_ptr)->matrix[i][j] = a->matrix[i][j] * coef;
    return (0);
}

int matrix_point_div(matrix_t **matrix_ptr, matrix_t *a, matrix_t *b)
{
    if (!a || !b)
        return (error_int(ERROR_NULL_PARAMETER));
    if (a->rows != b->rows || a->cols != b->cols)
        return (error_int(ERROR_NOT_SAME_SIZE));
    if (matrix_as_param(matrix_ptr, a->rows, a->cols))
        return (-1);
    for (size_t i = 0; i < a->rows; i++)
        for (size_t j = 0; j < a->cols; i++)
            (*matrix_ptr)->matrix[i][j] = logf(a->matrix[i][j]);
    return (0);
}

int matrix_log(matrix_t **matrix_ptr, matrix_t *a)
{
    if (!a)
        return (error_int(ERROR_NULL_PARAMETER));
    if (matrix_as_param(matrix_ptr, a->rows, a->cols))
        return (-1);
    for (size_t i = 0; i < a->rows; i++)
        for (size_t j = 0; j < a->cols; i++)
            (*matrix_ptr)->matrix[i][j] = logf(a->matrix[i][j]);
    return (0);
}

int matrix_point_sigmoid(matrix_t **matrix_ptr, matrix_t *a)
{
    matrix_t *result;

    if (!a)
        return (error_int(ERROR_NULL_PARAMETER));
    if (matrix_as_param(matrix_ptr, a->rows, a->cols))
        return (-1);
    result = *matrix_ptr;
    for (size_t i = 0; i < a->rows; i++)
        for (size_t j = 0; j < a->cols; j++)
            result->matrix[i][j] = 1 / (1 + expf(-a->matrix[i][j]));
    return (0);
}
