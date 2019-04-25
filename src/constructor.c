#include "private.h"

matrix_t *custom(size_t rows, size_t cols, float value)
{
    matrix_t *matrix;

    if (!rows || !cols)
        return (error_ptr(ERROR_SIZE_ZERO));
    if (!(matrix = malloc(sizeof(matrix_t))))
        return (error_ptr(ERROR_MALLOC));
    matrix->rows = rows;
    matrix->cols = cols;
    if (!(matrix->matrix = malloc(sizeof(float *) * matrix->rows)))
        return (error_ptr(ERROR_MALLOC));
    for (size_t i = 0; i < rows; i++) {
        if (!(matrix->matrix[i] = malloc(sizeof(float) * cols)))
            return (error_ptr(ERROR_MALLOC));
        for (size_t j = 0; j < cols; j++)
            matrix->matrix[i][j] = value;
    }
    return (matrix);
}

matrix_t *zeros(size_t rows, size_t cols)
{
    return (custom(rows, cols, 0));
}

matrix_t *identity(size_t n)
{
    matrix_t *matrix;

    if (!n)
        return (error_ptr(ERROR_SIZE_ZERO));
    matrix = custom(n, n, 0);
    for (size_t i = 0; i < n; i++)
        matrix->matrix[i][i] = 1;
    return (matrix);    
}

matrix_t *matrix_copy(matrix_t *a)
{
    matrix_t *matrix;

    if (!a)
        return (error_ptr(ERROR_NULL_PARAMETER));
    if (!(matrix = zeros(a->rows, a->cols)))
        return (NULL);
    for (size_t i = 0; i < matrix->rows; i++)
        for (size_t j = 0; j < matrix->cols; j++)
            matrix->matrix[i][j] = a->matrix[i][j];
    return (matrix);
}