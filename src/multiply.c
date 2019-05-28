#include "private.h"

int this_matrix_mul(matrix_t *res, matrix_t *a, matrix_t *b)
{
    size_t rows = a->rows;
    size_t cols = b->cols;
    size_t len = a->cols;
    float imp = 0;

    if (res == a || res == b)
        return (error_int("You must bufferise your matrix before multiply"));
    if (a->cols != b->rows) 
        return (error_int(ERROR_MUL_ROWS_COLS));
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++) {
            imp = 0;
            for (size_t k = 0; k < len; k++)
                imp += a->matrix[i][k] * b->matrix[k][j];
            res->matrix[i][j] = imp;
        }
    return (0);
}

int this_matrix_add_mul(matrix_t *res, matrix_t *a, matrix_t *b)
{
    size_t rows = a->rows;
    size_t cols = b->cols;
    size_t len = a->cols;
    float imp = 0;

    if (res == a || res == b)
        return (error_int("You must bufferise your matrix before multiply"));
    if (a->cols != b->rows) 
        return (error_int(ERROR_MUL_ROWS_COLS));
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++) {
            imp = 0;
            for (size_t k = 0; k < len; k++)
                imp += a->matrix[i][k] * b->matrix[k][j];
            res->matrix[i][j] += imp;
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

/*
** Use a as transpose to multiply
*/
int this_matrix_mul_transposed(matrix_t *res, matrix_t *a, matrix_t *b)
{
    size_t cols_a = a->cols;
    size_t cols_b = b->cols;
    size_t len = a->rows;
    float imp;

    if (a->rows != b->rows) 
        return (error_int(ERROR_MUL_ROWS_COLS));
    for (size_t i = 0; i < cols_a; i++)
        for (size_t j = 0; j < cols_b; j++) {
            imp = 0;
            for (size_t k = 0; k < len; k++)
                imp += a->matrix[k][i] * b->matrix[k][j];
            res->matrix[i][j] = imp;
        }
    return (0);
}

/*
** Use b as transpose to multiply
*/
int this_matrix_mul_nt(matrix_t *res, matrix_t *a, matrix_t *b)
{
    size_t rows_a = a->rows;
    size_t rows_b = b->rows;
    size_t len = a->cols;
    float imp;

    if (a->cols != b->cols) 
        return (error_int(ERROR_MUL_ROWS_COLS));
    for (size_t i = 0; i < rows_a; i++)
        for (size_t j = 0; j < rows_b; j++) {
            imp = 0;
            for (size_t k = 0; k < len; k++)
                imp += a->matrix[i][k] * b->matrix[j][k];
            res->matrix[i][j] = imp;
        }
    return (0);
}
