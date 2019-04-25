#include "private.h"

int matrix_display_prec(matrix_t *matrix, int prec)
{
    if (!matrix)
        return (-1);
    for (size_t i = 0; i < matrix->rows; i++) {
        for (size_t j = 0; j < matrix->cols; j++)
            printf("% .*f ", prec, matrix->matrix[i][j]);
        printf("\n");
    }
    return (0);
}

int matrix_display(matrix_t *matrix)
{
    return (matrix_display_prec(matrix, 2));
}