#include "private.h"

matrix_t *matrix_sub(matrix_t *a, matrix_t *b)
{
    matrix_t *matrix;

    if (!a || !b || a->cols != b->cols || a->rows != b->rows)
        return (NULL);
    if (!(matrix = zeros(a->rows, a->cols)))
        return (NULL);
    for (size_t i = 0; i < a->rows; i++)
        for (size_t j = 0; j < a->cols; j++)
            matrix->matrix[i][j] = a->matrix[i][j] - b->matrix[i][j];
    return (matrix);
}