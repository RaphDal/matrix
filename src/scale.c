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
