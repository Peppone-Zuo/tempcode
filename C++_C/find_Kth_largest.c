#include <stdio.h>
#include <stdlib.h>



typedef int elemtype;
int random_in_range(unsigned int, unsigned int);
elemtype get_Kth_largest(elemtype *, int, int);


int main()
{
    int i = 0;
    for (i = 0; i < 10; i++) {
        printf("%d\n", random_in_range(1, 10));
    }
    getchar();
    return 0;
}

elemtype get_Kth_largest(elemtype *seq, int k, int len)
{
}

int random_in_range (unsigned int min, unsigned int max)
{
    int base_random = rand(); /* in [0, RAND_MAX] */
    if (RAND_MAX == base_random) return random_in_range(min, max);
    /* now guaranteed to be in [0, RAND_MAX) */
    int range       = max - min,
        remainder   = RAND_MAX % range,
        bucket      = RAND_MAX / range;
    /* There are range buckets, plus one smaller interval
       within remainder of RAND_MAX */
    if (base_random < RAND_MAX - remainder) {
        return min + base_random/bucket;
    } else {
        return random_in_range (min, max);
    }
}
