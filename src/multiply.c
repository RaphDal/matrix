#include "private.h"

int matrix_addmul(matrix_t **matrix_ptr, matrix_t *a, matrix_t *b)
{
    float add;

    if (!a || !b)
        return (error_int(ERROR_NULL_PARAMETER));
    if (a->cols != b->rows)
        return (error_int(ERROR_MUL_ROWS_COLS));
    if (matrix_as_param(matrix_ptr, a->rows, b->cols))
        return (-1);
    for (size_t i = 0; i < a->rows; i++)
        for (size_t j = 0; j < b->cols; j++) {
            add = 0;
            for (size_t k = 0; k < a->cols; k++)
                add += a->matrix[i][k] * b->matrix[k][j];
            (*matrix_ptr)->matrix[i][j] += add; 
        }
    return (0);
}

int matrix_mul(matrix_t **matrix_ptr, matrix_t *a, matrix_t *b)
{
    float add;

    if (!a || !b)
        return (error_int(ERROR_NULL_PARAMETER));
    if (a->cols != b->rows)
        return (error_int(ERROR_MUL_ROWS_COLS));
    if (matrix_as_param(matrix_ptr, a->rows, b->cols))
        return (-1);
    for (size_t i = 0; i < a->rows; i++)
        for (size_t j = 0; j < b->cols; j++) {
            add = 0;
            for (size_t k = 0; k < a->cols; k++)
                add += a->matrix[i][k] * b->matrix[k][j];
            (*matrix_ptr)->matrix[i][j] = add; 
        }
    return (0);
}

int matrix_mul_tn(matrix_t **matrix_ptr, matrix_t *a, matrix_t *b)
{
    float add;

    if (!a || !b)
        return (error_int(ERROR_NULL_PARAMETER));
    if (a->rows != b->rows)
        return (error_int(ERROR_MUL_ROWS_COLS));
    if (matrix_as_param(matrix_ptr, a->cols, b->cols))
        return (-1);
    for (size_t i = 0; i < a->cols; i++)
        for (size_t j = 0; j < b->cols; j++) {
            add = 0;
            for (size_t k = 0; k < a->rows; k++)
                add += a->matrix[k][i] * b->matrix[k][j];
            (*matrix_ptr)->matrix[i][j] = add; 
        }
    return (0);
}

int matrix_mul_nt(matrix_t **matrix_ptr, matrix_t *a, matrix_t *b)
{
    float add;

    if (!a || !b)
        return (error_int(ERROR_NULL_PARAMETER));
    if (a->cols != b->cols)
        return (error_int(ERROR_MUL_ROWS_COLS));
    if (matrix_as_param(matrix_ptr, a->rows, b->rows))
        return (-1);
    for (size_t i = 0; i < a->rows; i++)
        for (size_t j = 0; j < b->rows; j++) {
            add = 0;
            for (size_t k = 0; k < a->cols; k++)
                add += a->matrix[i][k] * b->matrix[j][k];
            (*matrix_ptr)->matrix[i][j] = add; 
        }
    return (0);
}

int matrix_mul_tt(matrix_t **matrix_ptr, matrix_t *a, matrix_t *b)
{
    float add;

    if (!a || !b)
        return (error_int(ERROR_NULL_PARAMETER));
    if (a->rows != b->cols)
        return (error_int(ERROR_MUL_ROWS_COLS));
    if (matrix_as_param(matrix_ptr, a->cols, b->rows))
        return (-1);
    for (size_t i = 0; i < a->cols; i++)
        for (size_t j = 0; j < b->rows; j++) {
            add = 0;
            for (size_t k = 0; k < a->rows; k++)
                add += a->matrix[k][i] * b->matrix[j][k];
            (*matrix_ptr)->matrix[i][j] = add; 
        }
    return (0);
}
