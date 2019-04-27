#ifndef PRIVATE_H_
#define PRIVATE_H_

#include "matrix.h"
#include "errors.h"

/*
** errors.c
*/

void *error_ptr(char const *msg);
int error_int(char const *msg);
bool error_bool(char const *msg);
float error_float(char const *msg);

#endif /* !PRIVATE_H_ */
