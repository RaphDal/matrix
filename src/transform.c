#include "private.h"

matrix_t *matrix_transpose(matrix_t *a)
{
    matrix_t *matrix;

    if (!a)
        return (error_ptr(ERROR_NULL_PARAMETER));
    if (!(matrix = zeros(a->cols, a->rows)))
        return (NULL);
    for (size_t i = 0; i < a->rows; i++)
        for (size_t j = 0; j < a->cols; j++)
            matrix->matrix[j][i] = a->matrix[i][j];
    return (matrix);
}