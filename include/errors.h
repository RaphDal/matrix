#ifndef ERRORS_H_
#define ERRORS_H_

#define ERROR_SIZE_ZERO "Matrix's sizes must be superior or equal to 1"
#define ERROR_MALLOC    "Failed to allocate memory to the matrix"
#define ERROR_NULL_PARAMETER    "Matrix sent in parameter does not exist"
#define ERROR_NOT_SAME_SIZE "Matrices haven't the same size"
#define ERROR_MUL_ROWS_COLS "Matrix a columns isn't equal to matrix b rows, undefined result"
#define ERROR_NOSQUARED_MATRIX  "Matrix isn't squared"
#define ERROR_NORMAL_LIMIT  "Normal equation could be very long to calculate, if you want to try anymay you can modify normal_limit variable"
#define ERROR_NO_FILE "File not found"
#define ERROR_BAD_SIZE_PARAM "Matrix sent as parameter haven't the good size"
#endif /* !ERRORS_H_ */
