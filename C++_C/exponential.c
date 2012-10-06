#include <stdio.h>
#include <assert.h>
#include "mybool.h"

typedef long int elemtype;

elemtype Pow(elemtype X, unsigned int N);
void test_Pow(void);


int main(void)
{
    test_Pow();
    return 0;
}

elemtype Pow(elemtype X, unsigned int N)
{
    if (N == 0)
        return 1;
    else if (N % 2 == 0)
    {
        return Pow(X * X, N / 2);
    }
    else
        return Pow(X, N - 1) * X;
}

void test_Pow(void)
{
    assert(pow(2, 3) == 8);
    assert(pow(2, 10) == 1024);
    assert(pow(1000, 0) == 1);
    assert(pow(5, 3) == 125);
    printf("passed!\n");
}


