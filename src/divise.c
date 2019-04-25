#include "private.h"

matrix_t *matrix_div(matrix_t *a, matrix_t *b)
{
    matrix_t *matrix;
    float res;

    if (!a || !b)
        return (error_ptr(ERROR_NULL_PARAMETER));
    if (a->cols != b->rows)
        return (error_ptr(ERROR_MUL_ROWS_COLS));
    if (!(matrix = zeros(a->rows, b->cols)))
        return (NULL);
    for (size_t i = 0; i < matrix->rows; i++)
        for (size_t j = 0; j < matrix->cols; j++) {
            res = 0;
            for (size_t k = 0; k < a->cols; k++)
                res += a->matrix[i][k] / b->matrix[k][j];
            matrix->matrix[i][j] = res;
        }
    return (matrix);
}

matrix_t *matrix_inverse(matrix_t *a)
{
    matrix_t *matrix;

    if (!a)
        return (error_ptr(ERROR_NULL_PARAMETER));
    if (!(matrix = matrix_copy(a)))
        return (NULL);
    for (size_t i = 0; i < matrix->rows; i++)
        for (size_t j = 0; j < matrix->cols; j++)
            matrix->matrix[i][j] = 1 / matrix->matrix[i][j];
    return (matrix);
}