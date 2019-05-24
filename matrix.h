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
** addition.c
*/

matrix_t *matrix_add(matrix_t *a, matrix_t *b);

/*
** substract.c
*/

int this_matrix_add(matrix_t *res, matrix_t *a, matrix_t *b);
matrix_t *matrix_sub(matrix_t *a, matrix_t *b);

/*
** multiply.c
*/

int matrix_scale(matrix_t *matrix, float coef);
int this_matrix_mul(matrix_t *res, matrix_t *a, matrix_t *b);
matrix_t *matrix_mul(matrix_t *a, matrix_t *b);

/*
** divise.c
*/

matrix_t *matrix_div(matrix_t *a, matrix_t *b);

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
** normal.c
*/

matrix_t *matrix_normal(matrix_t *features, matrix_t *labels);


/*
** size.c
*/

matrix_t *matrix_size(matrix_t *matrix);

#endif /* !MATRIX_H_ */