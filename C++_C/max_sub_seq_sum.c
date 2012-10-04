#include <stdio.h>
#include <stdlib.h>



typedef int elemtype;
int random_in_range(unsigned int, unsigned int);
int get_max_subseq_sum1(int *, int);
int get_max_subseq_sum2(int *, int);
int get_max_subseq_sum3(int *, int);
int get_max_subseq_sum4(int *, int, int);

int main() 
{
    int array[] = {-2, 11, -4, 13, -5, -2};
    printf("using algorigthm 1 %d\n", get_max_subseq_sum1(array, 6));
    printf("using algorigthm 2 %d\n", get_max_subseq_sum2(array, 6));
    printf("using algorigthm 3 %d\n", get_max_subseq_sum3(array, 6));
    printf("using algorigthm 4 %d\n", get_max_subseq_sum4(array, 0, 5));
    //getchar();
    return 0;
}

int get_max_subseq_sum4(int *A, int left, int right)
{
    int ix = 0;
    int center = 0;
    int max_sum = 0;
    int max_right = 0, max_left = 0;
    int max_border_right = 0, max_border_left = 0;
    int border_right = 0, border_left = 0;
    if (left == right)
        return A[left] > 0 ? A[left] : 0;
    center = (left + right) / 2;
    max_right = get_max_subseq_sum4(A, center + 1, right);
    max_left = get_max_subseq_sum4(A, left, center);

    border_right = 0; max_border_right = 0;
    for (ix = center + 1; ix <= right; ix++)
    {
        border_right += A[ix];
        if (border_right > max_border_right)
            max_border_right = border_right;
    }

    border_left = 0; max_border_left = 0;
    for (ix = center; ix >= left; ix--)
    {
        border_left += A[ix];
        if (border_left > max_border_left)
            max_border_left = border_left;
    }
    
    max_sum = max_right > max_left ? max_right : max_left;
    max_sum = max_sum > (max_border_right + max_border_left) ? max_sum : \
              (max_border_right + max_border_left);

    return max_sum;
}

int get_max_subseq_sum3(int *A, int N)
{
    int i, j;
    int max = 0;
    int current_sum = 0;
    for (i = 0; i < N; i++)
    {
        current_sum += A[i];
        if (current_sum > max) max = current_sum;
        if (current_sum < 0) current_sum = 0;
    }
    return max;
}

int get_max_subseq_sum2(int *A, int N)
{
    int i, j;
    int max = 0;
    int current_sum = 0;
    for (i = 0; i < N; i++)
    {
        current_sum = 0;
        for (j = i; j < N; j++)
        {
            current_sum += A[j];

            if (current_sum > max)
                max = current_sum;
        }
    }
    return max;
}

int get_max_subseq_sum1(int *A, int N)
{
    int i, j, k;
    int max = 0;
    int current_sum = 0;
    for (i = 0; i < N; i++)
    {
        for (j = i; j < N; j++)
        {
            current_sum = 0;
            for (k = i; k <= j; k++) 
            {
                current_sum += A[k];
            }
            if (current_sum > max)
                max = current_sum;
        }
    }
    return max;
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
