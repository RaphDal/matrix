#include "private.h"

int matrix_size(matrix_t **matrix_ptr, matrix_t *a)
{
    if (!a)
        return (error_int(ERROR_NULL_PARAMETER));
    if (matrix_as_param(matrix_ptr, 1, 2))
        return (-1);
    (*matrix_ptr)->matrix[0][0] = a->rows;
    (*matrix_ptr)->matrix[0][1] = a->cols;
    return (0);
}

int matrix_disp_size(matrix_t *a)
{
    matrix_t *buff = NULL;

    if (matrix_size(&buff, a))
        return (-1);
    matrix_display(buff);
    matrix_destroy(buff);
    return (0);
}