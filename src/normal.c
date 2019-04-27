#include "private.h"

matrix_t *matrix_normal(matrix_t *features, matrix_t *labels)
{
    matrix_t *transpose;
    matrix_t *inverse;
    matrix_t *preres;
    matrix_t *res;

    if (!features || !labels)
        return (error_ptr(ERROR_NULL_PARAMETER));
    if (features->cols > normal_limit)
        return (error_ptr(ERROR_NORMAL_LIMIT));
    if (!(transpose = matrix_transpose(features)))
        return (NULL);
    if (!(preres = matrix_mul(transpose, features)))
        return (NULL);
    if (!(inverse = matrix_inverse(preres)))
        return (NULL);
    matrix_destroy(preres);
    if (!(preres = matrix_mul(inverse, transpose)))
        return (NULL);
    matrix_destroy(transpose);
    matrix_destroy(inverse);
    if (!(res = matrix_mul(preres, labels)))
        return (NULL);
    matrix_destroy(preres);
    return (res);
}