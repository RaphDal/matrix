#ifndef MATRIX_H_
#define MATRIX_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct matrix matrix_t;

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

matrix_t *matrix_sub(matrix_t *a, matrix_t *b);

/*
** multiply.c
*/

int matrix_scale(matrix_t *matrix, float coef);
matrix_t *matrix_mul(matrix_t *a, matrix_t *b);

/*
** divise.c
*/

matrix_t *matrix_div(matrix_t *a, matrix_t *b);
matrix_t *matrix_inverse(matrix_t *a);

#endif /* !MATRIX_H_ */