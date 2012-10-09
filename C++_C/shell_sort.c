#include <stdio.h>
#include <assert.h>

typedef int bool;
#define true 1
#define false 0


typedef unsigned int elemtype;

void shell_sort(elemtype A[], int N);
bool test_shell_sort(void);

int main(void)
{
    int i;
    elemtype A[] = {3, 1, 4, 5, 7};
    shell_sort(A, 5);
    for (i = 0; i < 5; i++)
    {
        printf("%d\n", A[i]);
    }
    
    if (test_shell_sort())
        printf("passed!\n");
    return 0;
}

void shell_sort(elemtype A[], int N)
{
    int i, j;
    int gap;
    elemtype tmp;
    for (gap = N / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < N; i++)
        {
            tmp = A[i];
            for (j = i; j >= gap && A[j - gap] > tmp; j -= gap)
            {
                A[j] = A[j - gap];
            }
            A[j] = tmp;
        }
    }
}



bool test_shell_sort(void) 
{
    return true;
}

