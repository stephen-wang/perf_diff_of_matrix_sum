#include "timeit.h"

#include <assert.h>
#include <stdlib.h> // for random(), srandom()
#include <stdint.h>
#include <time.h>   // for time()


int rand_int(int a, int b)
{
    assert(a < b);
    return (random() % (b-a)) + a;
}


void init_matrix(uint64_t* m, int size)
{
    srandom(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            *(m + i * size + j) = rand_int(0, 25);
            //if (i < 10 && j < 10)
            //    printf("%3ld ", *(m+i*size+j));
        }
    }
}


uint64_t sum_matrix_row_based(uint64_t* m, int size)
{
    uint64_t result = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
             result += *(m + i * size + j);

    return result;
}


uint64_t sum_matrix_col_based(uint64_t* m, int size)
{
    uint64_t result = 0;
    for (int j = 0; j < size; j++)
        for (int i = 0; i < size; i++)
             result += *(m + i * size + j);

    return result;
}


int main(int argc, char **argv)
{
    
    uint64_t* matrix;

    if (argc != 2) { 
        printf("Usage: sum_matrix ${matrix_size}\n");
        exit(-1);
    }


    int size = atoi(argv[1]);
    matrix = (uint64_t*) malloc(size * size * sizeof(uint64_t));
    init_matrix(matrix, size);

    printf("sum_matrix_row_based(matrix[%d][%d]):\n", size, size);
    timeit(1, sum_matrix_row_based, matrix, size);
    printf("\n");
    printf("sum_matrix_col_based(matrix[%d][%d]):\n", size, size);
    timeit(1, sum_matrix_col_based, matrix, size);

    free(matrix);
    printf("\n\n");
}
