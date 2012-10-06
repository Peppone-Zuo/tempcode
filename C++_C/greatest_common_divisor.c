#include <stdio.h>
#include <assert.h>

typedef int bool;
#define true 1
#define false 0


typedef unsigned int elemtype;

elemtype gcd(elemtype M, elemtype N);

int main(void)
{
    if (test_gcd())
        printf("passed!\n");
    return 0;
}

elemtype gcd(elemtype M, elemtype N)
{
    elemtype Rem;
    while (N > 0)
    {
        Rem = M % N;
        M = N;
        N = Rem;
    }
    return M;
}

bool test_gcd(void)
{
    elemtype m, n;
    m = 1989;
    n = 1590;
    assert(gcd(m, n) == 3);
    return true;
}

