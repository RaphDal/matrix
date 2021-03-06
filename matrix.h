#ifndef MATRIX_H_
#define MATRIX_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct matrix
{
    size_t rows;
    size_t cols;

    float **matrix;
} matrix_t;

static bool disperror = true;

static size_t normal_limit = 10000;


/*
** constructor.c
*/

matrix_t *custom(size_t rows, size_t cols, float value);
matrix_t *zeros(size_t rows, size_t cols);
matrix_t *identity(size_t n);
matrix_t *matrix_copy(matrix_t *a);


/*
** destroy.c
*/

int matrix_destroy(matrix_t *matrix);


/*
** display.c
*/

int matrix_display_prec(matrix_t *matrix, int prec);
int matrix_display(matrix_t *matrix);


/*
** add_sub.c
*/

int matrix_add(matrix_t **matrix_ptr, matrix_t *a, matrix_t *b);
int matrix_sub(matrix_t **matrix_ptr, matrix_t *a, matrix_t *b);


/*
** multiply.c
*/

int matrix_addmul(matrix_t **matrix_ptr, matrix_t *a, matrix_t *b);
int matrix_mul(matrix_t **matrix_ptr, matrix_t *a, matrix_t *b);
int matrix_mul_tn(matrix_t **matrix_ptr, matrix_t *a, matrix_t *b);
int matrix_mul_nt(matrix_t **matrix_ptr, matrix_t *a, matrix_t *b);
int matrix_mul_tt(matrix_t **matrix_ptr, matrix_t *a, matrix_t *b);


/*
** conditions.c
*/

bool matrix_is_squared(matrix_t *a);
bool matrix_is_multiplicable(matrix_t *a, matrix_t *b);


/*
** transform.c
*/

matrix_t *matrix_transpose(matrix_t *a);
matrix_t *matrix_inverse(matrix_t *a);
matrix_t *matrix_cofactor(matrix_t *a);


/*
** str.c
*/

char *matrix_getstr(matrix_t *a, int prec);


/*
** size.c
*/

int matrix_size(matrix_t **matrix_ptr, matrix_t *a);
int matrix_disp_size(matrix_t *a);


/*
** point.c
*/

int matrix_point_mul(matrix_t **matrix_ptr, matrix_t *a, float coef);
int matrix_log(matrix_t **matrix_ptr, matrix_t *a);
int matrix_point_sigmoid(matrix_t **matrix_ptr, matrix_t *a);
int matrix_point_div(matrix_t **matrix_ptr, matrix_t *a, matrix_t *b);


/*
** errors.c
*/

void *error_ptr(char const *msg);
int error_int(char const *msg);
bool error_bool(char const *msg);
float error_float(char const *msg);


/*
** import.c
*/

matrix_t *matrix_import_mat(char const *filepath);

#endif /* !MATRIX_H_ */