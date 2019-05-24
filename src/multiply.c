#include "private.h"

int this_matrix_mul(matrix_t *res, matrix_t *a, matrix_t *b)
{
    size_t rows = a->rows;
    size_t cols = b->cols;
    size_t len = a->cols;
    float imp = 0;

    if (a->cols != b->rows) 
        return (-1);
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++) {
            imp = 0;
            for (size_t k = 0; k < len; k++)
                imp += a->matrix[i][k] * b->matrix[k][j];
            res->matrix[i][j] = imp;
        }
    return (0);
}

matrix_t *matrix_mul(matrix_t *a, matrix_t *b)
{
    matrix_t *res;

    if (!a || !b)
        return (error_ptr(ERROR_NULL_PARAMETER));
    if (a->cols != b->rows)
        return (error_ptr(ERROR_MUL_ROWS_COLS));
    if (!(res = zeros(a->rows, b->cols)))
        return (NULL);
    this_matrix_mul(res, a, b);
    return (res);
}