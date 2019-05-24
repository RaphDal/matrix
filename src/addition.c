#include "private.h"

int this_matrix_add(matrix_t *res, matrix_t *a, matrix_t *b)
{
    size_t rows = res->rows;
    size_t cols = res->cols;
    float **arr_res = res->matrix;
    float **arr_a = a->matrix;
    float **arr_b = b->matrix;

    if (res->rows != a->rows || res->rows != b->rows ||
    res->cols != a->cols || res->cols != b->cols)
        return (-1);
    for(size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            arr_res[i][j] = arr_a[i][j] + arr_b[i][j];
    return (0);
}

matrix_t *matrix_add(matrix_t *a, matrix_t *b)
{
    matrix_t *matrix;

    if (!a || !b)
        return (error_ptr(ERROR_NULL_PARAMETER));
    if (a->cols != b->cols || a->rows != b->rows)
        return (error_ptr(ERROR_NOT_SAME_SIZE));
    if (!(matrix = zeros(a->rows, a->cols)))
        return (NULL);
    this_matrix_add(matrix, a, b);
    return (matrix);
}