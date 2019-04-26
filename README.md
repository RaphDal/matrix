# Matrix: A simple matrix library easy-to-use.

### Table of contents

0. [Getting started](#setup)
1. [Create your matrix](#create-matrix)
2. [Basics functions](#basics)

<a name='setup'></a>
## 0. Getting started
For this project you need to have [Make](https://en.wikipedia.org/wiki/Make_(software)) and [g++](https://fr.wikipedia.org/wiki/GNU_Compiler_Collection)

In the directory, you can compile the library by using the command `$ make`

<a name='create-matrix'></a>
## 1. Create your matrix

```c
int main(int argc, char * const *argv)
{
    // Create a new matrix of 2 x 3.
    matrix_t *matrix = zeros(2, 3);

    // Display the matrix content
    matrix_display(matrix);

    return (0);
}
```

### Functions to create matrix

There are different functions to create a matrix.
The next functions are going to have several parameters in common. Other parameters will be descripted directly in the functions description.

* __rows__ - _Number_ - The number of rows in the matrix.
* __cols__ - _Number_ - The number of columns in the matrix. 

#### zeros(rows, cols)

This function create a matrix of rows x cols, filled with zeros.

```c
// Create a matrix of 2 x 3.
zeros(2, 3);
```


#### custom(rows, cols, value)

This function create a matrix of rows x cols, filled with value.

* __value__ - _Float_ - The value used to fill the matrix.

```c
// Create a matrix of 4 x 1 filled with -1.
custom(4, 1, -1);
```


#### identity(n)

This function create a n x n identity matrix.

* __n__ - _Number_ - Size of the matrix (n x n).

```c
// Create a 4 x 4 identity matrix.
identity(4);
```


#### matrix_destroy(matrix)

This function destroy properly `matrix`.

```c
matrix_destroy(matrix);
```

<a name='basics'></a>
## 2. Mathematical functions you can use with your matrix.

The next functions are going to have several parameters in common. Other parameters will be descripted directly in the functions description.

* __a__ - _Matrix_ - The first matrix.
* __b__ - _Matrix_ - The second matrix.

#### matrix_display_prec(a, prec)

This function will display the matrix `a` with a precision of `prec`.

* __prec__ - _Number_ - Number of digits after the point (default : 2).

```c
// Display the matrix a with a precision of 5.
matrix_display_prec(a, 5);
```

#### matrix_add(a, b)

This function return a new matrix who is the sum of the matrix `a` and the matrix `b`.

```c
// This will add the matrix a and b and put the result in sum.
matrix_t *sum = matrix_add(a, b);

// Then the result is displayed in the standard output.
matrix_display(sum);
```

#### matrix_sub(a, b)

This function return a new matrix who is the substract of the matrix `a` by the matrix `b`.

```c
// This will substract the matrix a by b and put the result in sub.
matrix_t *sub = matrix_sub(a, b);

// Then the result is displayed in the standard output.
matrix_display(sub);
```

#### matrix_scale(a, coef)

This function multiply the matrix `a` by the factor `coef`.

```c
// Create a new 3 x 4 matrix filled with 2
matrix_t *matrix = custom(3, 4, 2);

// Multiplie matrix values by 1.5
matrix_scale(matrix, 1.5);

// Display the matrix (filled with 3 so)
matrix_display(matrix);
```

#### matrix_mul(a, b)

This function return a new matrix who is the multiplication of the matrix `a` by the matrix `b`.

```c
// This will multiply the matrix a by b and put the result in sub.
matrix_t *mul = matrix_sub(a, b);

// Then the result is displayed in the standard output.
matrix_display(mul);
```

#### matrix_div(a, b)

This function return a new matrix who is the division of the matrix `a` by the matrix `b`.

```c
// This will multiply the matrix a by b and put the result in sub.
matrix_t *div = matrix_sub(a, b);

// Then the result is displayed in the standard output.
matrix_display(div);
```