#include <stdio.h>
#include <assert.h>

typedef int bool;
#define true 1
#define false 0


typedef unsigned int elemtype;

void select_sort(elemtype A[], int N);
bool test_select_sort(void);

int main(void)
{
    int i;
    elemtype A[] = {3, 1, 4, 5, 7};
    select_sort(A, 5);
    for (i = 0; i < 5; i++)
    {
        printf("%d\n", A[i]);
    }
    
    if (test_select_sort())
        printf("passed!\n");
    return 0;
}

void select_sort(elemtype A[], int N)
{
    int j, k, max_index;
    elemtype tmp;
    for (j = 0; j < N; j++)
    {
        max_index = j;
        for (k = j + 1; k < N; k++)
        {
            if (A[k] > A[max_index])
            {
                max_index = k;
            }
        }
        tmp = A[j];
        A[j] = A[max_index];
        A[max_index] = tmp;
    }
}



bool test_select_sort(void) 
{
    return true;
}

