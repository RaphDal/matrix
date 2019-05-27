#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include "private.h"

static matrix_t *matrix_sized_import(FILE *file)
{
    char *buff;
    size_t n = 0;
    size_t rows = 0;
    size_t cols = 0;

    while (!rows || !cols) {
        buff = NULL;
        if (getline(&buff, &n, file) == -1)
            return (NULL);
        if (strlen(buff) > 6 && !strncmp(buff + 2, "rows: ", 6))
            rows = atoi(buff + 8);
        if (strlen(buff) > 6 && !strncmp(buff + 2, "columns: ", 9))
            cols = atoi(buff + 11);
    }
    if (!cols || !rows)
        return (NULL);
    return (zeros(rows, cols));
}

int fill_columns(matrix_t *matrix, char *line, size_t row)
{
    char *token = strtok(line, " ");
    size_t j;

    if (!token)
        return (-1);
    for (j = 0; j < matrix->cols - 1; j++) {
        matrix->matrix[row][j] = strtof(token, NULL);
        token = strtok(NULL, " ");
        if (!token)
            return (-1);
    }
    matrix->matrix[row][j] = strtof(token, NULL);
    return (0);
}

int fill_rows(matrix_t *matrix, FILE *file)
{
    char *buff;
    size_t n = 0;

    for (size_t i = 0; i < matrix->rows; i++) {
        buff = NULL;
        if (getline(&buff, &n, file) == -1)
            return (-1);
        if (fill_columns(matrix, buff, i) == -1)
            return (-1);
    }
    return (0);
}

matrix_t *matrix_import_mat(char const *filepath)
{
    matrix_t *res;
    FILE *file = fopen(filepath, "r");

    if (!file)
        return (error_ptr(ERROR_NO_FILE));
    if (!(res = matrix_sized_import(file)))
        return (NULL);
    if (fill_rows(res, file)) {
        printf("Error during parsing\n");
        return (NULL);
    }
    matrix_display(res);
    return (res);
}