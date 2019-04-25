#ifndef PRIVATE_H_
#define PRIVATE_H_

#include "matrix.h"

struct matrix
{
    size_t rows;
    size_t cols;

    float **matrix;
};

/*
** errors.c
*/

void *error_ptr(char const *msg);
int error_int(char const *msg);

#endif /* !PRIVATE_H_ */
