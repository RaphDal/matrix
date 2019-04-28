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

static void matrix_pattern(matrix_t *a, matrix_t *buffer, size_t i, size_t j)
{
    int dec_rows = 0;
    int dec_cols = 0;

    for (size_t k = 0; k < a->rows - 1; k++) {
        dec_rows = k == i ? 1 : dec_rows;
        dec_cols = 0;
        for (size_t l = 0; l < a->cols - 1; l++) {
            dec_cols = l == j ? 1 : dec_cols;
            buffer->matrix[k][l] = a->matrix[k + dec_rows][l + dec_cols];
        }
    }
}

float matrix_determinant(matrix_t *a)
{
    float res = 0;
    float plus = 1;
    matrix_t *buffer;

    if (!a)
        return (error_float(ERROR_NULL_PARAMETER));
    if (a->rows != a->cols)
        return (error_float(ERROR_NOSQUARED_MATRIX));
    if (a->rows == 1)
        return (a->matrix[0][0]);
    if (a->rows == 2)
        return ((a->matrix[0][0] * a->matrix[1][1]) -
        (a->matrix[0][1] * a->matrix[1][0]));
    if (!(buffer = zeros(a->rows - 1, a->cols - 1)))
        return (-1);
    for (size_t i = 0; i < a->rows; i++) {
        matrix_pattern(a, buffer, i, 0);
        res += plus * a->matrix[i][0] * matrix_determinant(buffer);
        plus *= -1;
    }
    matrix_destroy(buffer);
    return (res);
}

matrix_t *matrix_cofactor(matrix_t *a)
{
    matrix_t *matrix;
    matrix_t *buffer;
    float plus = 1;

    if (!a)
        return (error_ptr(ERROR_NULL_PARAMETER));
    if (a->rows != a->cols)
        return (error_ptr(ERROR_NOSQUARED_MATRIX));
    if (!(matrix = matrix_copy(a)))
        return (NULL);
    if (!(buffer = zeros(a->rows - 1, a->cols - 1)))
        return (NULL);
    for (size_t i = 0; i < matrix->rows; i++) {
        for (size_t j = 0; j < matrix->cols; j++) {
            matrix_pattern(a, buffer, i, j);
            matrix->matrix[i][j] = plus * matrix_determinant(buffer);
            plus *= -1;
        }
    }
    matrix_destroy(buffer);
    return (matrix);
}

matrix_t *matrix_inverse(matrix_t *a)
{
    float det;
    matrix_t *b;
    matrix_t *matrix;

    if (!a)
        return (error_ptr(ERROR_NULL_PARAMETER));
    if (a->rows != a->cols)
        return (error_ptr(ERROR_NOSQUARED_MATRIX));
    det = matrix_determinant(a);
    b = matrix_cofactor(a);
    matrix = matrix_transpose(b);
    matrix_destroy(b);
    matrix_scale(matrix, 1 / det);
    return (matrix);
}