#include "private.h"

matrix_t *custom(size_t rows, size_t cols, float value)
{
    matrix_t *matrix;

    if (!rows || !cols || !(matrix = malloc(sizeof(matrix_t))))
        return (NULL);
    matrix->rows = rows;
    matrix->cols = cols;
    if (!(matrix->matrix = malloc(sizeof(float *) * matrix->rows)))
        return (NULL);
    for (size_t i = 0; i < rows; i++) {
        if (!(matrix->matrix[i] = malloc(sizeof(float) * cols)))
            return (NULL);
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
        return (NULL);
    matrix = custom(n, n, 0);
    for (size_t i = 0; i < n; i++)
        matrix->matrix[i][i] = 1;
    return (matrix);    
}