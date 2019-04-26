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

static matrix_t *matrix_pattern(matrix_t *a, size_t i, size_t j)
{
    int dec_rows = 0;
    int dec_cols = 0;
    matrix_t *matrix = zeros(a->rows - 1, a->cols - 1);

    if (!matrix)
        return (NULL);
    for (size_t k = 0; k < a->rows - 1; k++) {
        dec_rows = k == i ? 1 : dec_rows;
        dec_cols = 0;
        for (size_t l = 0; l < a->cols - 1; l++) {
            dec_cols = l == j ? 1 : dec_cols;
            matrix->matrix[k][l] = a->matrix[k + dec_rows][l + dec_cols];
        }
    }
    return (matrix);
}

float matrix_determinant(matrix_t *a)
{
    matrix_t *b;
    float res = 0;
    float plus = 1;

    if (!a)
        return (error_float(ERROR_NULL_PARAMETER));
    if (a->rows != a->cols)
        return (error_float(ERROR_NOSQUARED_MATRIX));
    if (a->rows == 1)
        return (a->matrix[0][0]);
    if (a->rows == 2)
        return ((a->matrix[0][0] * a->matrix[1][1]) -
        (a->matrix[0][1] * a->matrix[1][0]));
    for (size_t i = 0; i < a->rows; i++) {
        b = matrix_pattern(a, i, 0);
        res += plus * a->matrix[i][0] * matrix_determinant(b);
        matrix_destroy(b);
        plus *= -1;
    }
    return (res);
}