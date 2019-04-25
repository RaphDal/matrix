#include "private.h"

int matrix_scale(matrix_t *matrix, float coef)
{
    if (!matrix)
        return (error_int(ERROR_NULL_PARAMETER));
    for (size_t i = 0; i < matrix->rows; i++)
        for (size_t j = 0; j < matrix->cols; j++)
            matrix->matrix[i][j] *= coef;
    return (0);
}

matrix_t *matrix_mul(matrix_t *a, matrix_t *b)
{
    matrix_t *matrix;
    float res;

    if (a->cols != b->rows)
        return (error_ptr(ERROR_MUL_ROWS_COLS));
    if (!(matrix = zeros(a->rows, b->cols)))
        return (NULL);
    for (size_t i = 0; i < matrix->rows; i++)
        for (size_t j = 0; j < matrix->cols; j++) {
            res = 0;
            for (size_t k = 0; k < a->cols; k++)
                res += a->matrix[i][k] * b->matrix[k][j];
            matrix->matrix[i][j] = res;
        }
    return (matrix);
}