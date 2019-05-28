#include "private.h"

int matrix_add(matrix_t **matrix_ptr, matrix_t *a, matrix_t *b)
{
    matrix_t *result;

    if (!a)
        return (error_int(ERROR_NULL_PARAMETER));
    if (a->cols != b->cols || a->rows != b->rows)
        return (error_int(ERROR_NOT_SAME_SIZE));
    if (matrix_as_param(matrix_ptr, a->rows, a->cols))
        return (-1);
    result = *matrix_ptr;
    for (size_t i = 0; i < a->rows; i++)
        for (size_t j = 0; j < a->cols; j++)
            result->matrix[i][j] = a->matrix[i][j] + b->matrix[i][j];
    return (0);
}

int matrix_sub(matrix_t **matrix_ptr, matrix_t *a, matrix_t *b)
{
    matrix_t *result;

    if (!a)
        return (error_int(ERROR_NULL_PARAMETER));
    if (a->cols != b->cols || a->rows != b->rows)
        return (error_int(ERROR_NOT_SAME_SIZE));
    if (matrix_as_param(matrix_ptr, a->rows, a->cols))
        return (-1);
    result = *matrix_ptr;
    for (size_t i = 0; i < a->rows; i++)
        for (size_t j = 0; j < a->cols; j++)
            result->matrix[i][j] = a->matrix[i][j] - b->matrix[i][j];
    return (0);
}