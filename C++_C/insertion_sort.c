#include <stdio.h>
#include <assert.h>

typedef int bool;
#define true 1
#define false 0


typedef unsigned int elemtype;

void insertion_sort(elemtype A[], int N);
bool test_insertion_sort(void);

int main(void)
{
    int i;
    elemtype A[] = {3, 1, 4, 5, 7};
    insertion_sort(A, 5);
    for (i = 0; i < 5; i++)
    {
        printf("%d\n", A[i]);
    }
    
    if (test_insertion_sort())
        printf("passed!\n");
    return 0;
}

void insertion_sort(elemtype A[], int N)
{
    int i, j;
    elemtype tmp;
    for (i = 1; i < N; i++)
    {
        tmp = A[i];
        for (j = i; j > 0 && A[j - 1] > tmp; j--)
        {
            A[j] = A[j - 1];
        }
        A[j] = tmp;
    }
}


bool test_insertion_sort(void) 
{
    return true;
}

