#ifndef PRIVATE_H_
#define PRIVATE_H_

#include "matrix.h"

struct matrix
{
    size_t rows;
    size_t cols;

    float **matrix;
};

#endif /* !PRIVATE_H_ */
