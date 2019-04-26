#include "private.h"

char *matrix_getstr(matrix_t *a, int prec)
{
    char *buffer;
    size_t size;
    size_t index = 0;

    if (!a)
        return (error_ptr(ERROR_NULL_PARAMETER));
    size = a->rows * (a->cols * (prec + 4) + 3) + 1;
    if (!(buffer = malloc(sizeof(char) * size)))
        return (error_ptr(ERROR_MALLOC));
    buffer[index++] = '[';
    for (size_t i = 0; i < a->rows; i++) {
        buffer[index++] = '[';
        for (size_t j = 0; j < a->cols; j++) {
            sprintf(buffer + index, "% *.*f", prec + 3, prec, a->matrix[i][j]);
            index += prec + 3;
            if (j < a->cols - 1)
                buffer[index++] = ',';
        }
        buffer[index++] = ']';
        if (i < a->rows - 1) {
            buffer[index++] = ',';
            buffer[index++] = '\n';
        }
    }
    buffer[index++] = ']';
    buffer[index] = '\0';
    return (buffer);
}