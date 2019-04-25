#include "private.h"

int matrix_destroy(matrix_t *matrix)
{
    if (!matrix)
        return (-1);
    for (size_t i = 0; i < matrix->rows; i++)
        free(matrix->matrix[i]);
    free(matrix->matrix);
    free(matrix);
    return (0);
}