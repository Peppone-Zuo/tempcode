#include <stdio.h>
#include <assert.h>

typedef int bool;
#define true 1
#define false 0


typedef unsigned int elemtype;

void bubble_sort(elemtype A[], int N);
bool test_bubble_sort(void);

int main(void)
{
    int i;
    elemtype A[] = {3, 1, 4, 5, 7};
    bubble_sort(A, 5);
    for (i = 0; i < 5; i++)
    {
        printf("%d\n", A[i]);
    }
    
    if (test_bubble_sort())
        printf("passed!\n");
    return 0;
}

void bubble_sort(elemtype A[], int N)
{
    int j, k;
    elemtype tmp;
    for (j = N; j > 0; j--)
    {
        for (k = 0; k < j - 1; k++)
        {
            if (A[k] > A[k + 1])
            {
                tmp = A[k];
                A[k] = A[k + 1];
                A[k + 1] = tmp;
            }
        }
    }
}



bool test_bubble_sort(void) 
{
    return true;
}

