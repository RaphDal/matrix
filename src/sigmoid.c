#include <math.h>
#include "private.h"

int this_matrix_sigmoid(matrix_t *res, matrix_t *matrix)
{
    for (size_t i = 0; i < matrix->rows; i++)
        for (size_t j = 0; j < matrix->cols; j++)
            res->matrix[i][j] = 1 / (1 + expf(-matrix->matrix[i][j]));
    return (0);
}

int matrix_sigmoid(matrix_t *matrix)
{
    if (!matrix)
        return (error_int(ERROR_NULL_PARAMETER));
    this_matrix_sigmoid(matrix, matrix);
    return (0);
}