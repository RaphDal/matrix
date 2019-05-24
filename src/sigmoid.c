#include <math.h>
#include "private.h"

int matrix_sigmoid(matrix_t *matrix)
{
    if (!matrix)
        return (error_int(ERROR_NULL_PARAMETER));
    for (size_t i = 0; i < matrix->rows; i++)
        for (size_t j = 0; j < matrix->cols; j++)
            matrix->matrix[i][j] = 1 / (1 + expf(matrix->matrix[i][j]));
    return (0);
}