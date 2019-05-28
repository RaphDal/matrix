#include "private.h"

int matrix_as_param(matrix_t **matrix_ptr, size_t rows, size_t cols)
{
    matrix_t *matrix;
    
    if (!matrix_ptr)
        return (error_int(ERROR_NULL_PARAMETER));
    matrix = *matrix_ptr;
    if (matrix) {
        if (matrix->rows != rows || matrix->cols != cols)
            return (error_int(ERROR_BAD_SIZE_PARAM));
        return (0);
    }
    if (!(matrix = zeros(rows, cols)))
        return (-1);
    *matrix_ptr = matrix;
    return (0);
}