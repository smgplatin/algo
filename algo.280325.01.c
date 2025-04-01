// Create 2 matrices with the type of Matrix A: 2*3 and Matrix B: 3*2. Assign random values in between 0 to 100 and 0 is excluded. Add and multiply these matrices and print the result. If addition or multiplication is not possible, print "Addition or multiplication is not possible". Calculate only a*b, dont calculate b*a.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWA 2
#define COLA 3
#define ROWB 3
#define COLB 2

int matrixA[ROWA][COLA];
int matrixB[ROWB][COLB];
int summation[ROWA][COLA];
int targetMatrix[ROWA][COLB];

void randomValueGenerator(int matrixA[ROWA][COLA], int matrixB[ROWB][COLB]);
void printMatrix(int rows, int cols, int matrix[rows][cols]);
void sumMatrix(int matrixA[ROWA][COLA], int matrixB[ROWB][COLB]);
void multiplyMatrix(int matrixA[ROWA][COLA], int matrixB[ROWB][COLB]);


int main(void)
{
    srand(time(NULL));

    randomValueGenerator(matrixA, matrixB);

    printf("\n*** Matrix A ***\n");
    printMatrix(ROWA, COLA, matrixA);

    printf("\n*** Matrix B ***\n");
    printMatrix(ROWB, COLB, matrixB);

    printf("\n*** Sum of Matrices ***\n");
    sumMatrix(matrixA, matrixB);

    printf("\n*** Multiplication of Matrices ***\n");
    multiplyMatrix(matrixA, matrixB);

    return 0;
}

void randomValueGenerator(int matrixA[ROWA][COLA], int matrixB[ROWB][COLB])
{
    for (size_t i = 0; i < ROWA; ++i)
    {
        for (size_t j = 0; j < COLA; ++j)
        {
            matrixA[i][j] = (rand() % 100) + 1;
        }
    }

    for (size_t i = 0; i < ROWB; ++i)
    {
        for (size_t j = 0; j < COLB; ++j)
        {
            matrixB[i][j] = (rand() % 100) + 1;
        }
    }
}

void printMatrix(int rows, int cols, int matrix[rows][cols])
{
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void sumMatrix(int matrixA[ROWA][COLA], int matrixB[ROWB][COLB])
{
    if (ROWA != ROWB || COLA != COLB)
    {
        printf("UNDEFINED: Matrix types for summation is not possible!\n");

        return;
    }

    int summation[ROWA][COLA];

    for (size_t i = 0; i < ROWA; ++i)
    {
        for (size_t j = 0; j < COLA; ++j)
        {
            summation[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    printf("\n*** Summation of Matrices ***\n");
    printMatrix(ROWA, COLA, summation);
}

void multiplyMatrix(int matrixA[ROWA][COLA], int matrixB[ROWB][COLB])
{
    if (COLA != ROWB)
    {
        printf("UNDEFINED: Matrix types for multiplication is not possible!\n");

        return;
    }

    for (size_t i = 0; i < ROWA; ++i)
    {
        for (size_t j = 0; j < COLB; ++j)
        {
            targetMatrix[i][j] = 0;
            for (size_t k = 0; k < COLA; ++k)
            {
                targetMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    printMatrix(ROWA, COLB, targetMatrix);
}