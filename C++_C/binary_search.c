#include <stdio.h> 
#include <assert.h>

typedef int bool;
#define true 1
#define false 0


int binary_search(int *A, int to_search, int N);
bool test_binary_search();

int main(void)
{
    if(test_binary_search())
    {
        printf("right");
    }
    getchar();
    return 0;
}

int binary_search(int *A, int to_search, int N)
{
    int low = 0;
    int high = N - 1;
    int mid = 0;
    while (low <= high) 
    {
        mid = (low + high) / 2;
        if (to_search > A[mid])
            low = mid + 1;
        else if (to_search < A[mid])
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}

bool test_binary_search()
{
    int array[] = {1, 2, 4, 8, 10, 30, 32, 77};

    assert(binary_search(array, 30, 8) == 5);
    assert(binary_search(array, 3, 8) == -1);
    assert(binary_search(array, 77, 8) == 7);
    assert(binary_search(array, 2, 8) == 1);
    assert(binary_search(array, 10, 8) == 4);

    return true;
}

