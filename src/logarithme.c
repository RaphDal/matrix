#include "private.h"

int matrix_log(matrix_t *res, matrix_t *matrix)
{
    if (res->rows != matrix->rows || res->cols != matrix->cols)
        return (error_int(ERROR_NOT_SAME_SIZE));
    for (size_t i = 0; i < res->rows; i++)
        for (size_t j = 0; j < res->cols; j++)
            res->matrix[i][j] = log(matrix->matrix[i][j]);
    return (0);
}

int this_matrix_log(matrix_t *matrix)
{
    return (matrix_log(matrix, matrix));
}