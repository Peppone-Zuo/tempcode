#include <iostream>
using namespace std;



void swap(int *a, int *b);
void print(int A[], int N);

void insertion_sort(int A[], int N);
void bubble_sort(int A[], int N);
void shell_sort(int A[], int N);
void select_sort(int A[], int N);
void merge_sort(int A[], int N);
void merge_sort(int A[], int tmpArray[], int begin, int end);
void merge(int A[], int tmpArray[], int begin, int center, int end);
int median3(int A[], int left, int right);
void quick_sort(int A[], int N);
void quick_sort(int A[], int left, int right);

void test_median3(void);
const int size = 10;


int main(void)
{
    int i;
    int A[size] = {4, 2, 3, 9, 8, 5, 1, 7, 6, 11};
    
    print(A, size);
    //insertion_sort(A, size);
    //shell_sort(A, size);
    //bubble_sort(A, size);
    //merge_sort(A, size);
    //select_sort(A, size);
    quick_sort(A, size);
    print(A, size);

    return 0;
}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void print(int A[], int N)
{
    int ix;
    for (ix = 0; ix < N; ix++)
    {
        cout << A[ix] << ' ';
    }
    cout << endl;

}


void insertion_sort(int A[], int N)
{
    int tmp;
    int i, j;
    for (i = 1; i < N; i++)
    {
        tmp = A[i];
        for (j = i; j > 0 && A[j - 1] < tmp; j--)
        {
            A[j] = A[j - 1];
        }
        A[j] = tmp;
    }
}

void bubble_sort(int A[], int N)
{
    int tmp;
    int i, j;
    for (i = N - 1; i > 0; i--)
        for (j = 0; j < i; j++)
        {
            if (A[j] > A[j + 1])
            {
                tmp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp;
            }
        }
}


void shell_sort(int A[], int N)
{
    int tmp;
    int gap;
    int i, j;
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


void merge(int A[], int tmpArray[], int begin, int center, int end)
{
    int i, j, tmpPos;
    int length = end - begin + 1;
    i = begin;
    j = center;
    tmpPos = begin;
    while (i <= center-1 && j <= end)//at the beginning i wrote this in for loop and increase i and j int both the for loop and the body
    {
        if (A[i] <= A[j])
            tmpArray[tmpPos++] = A[i++];
        else
            tmpArray[tmpPos++] = A[j++];
    }
    while (i <= center - 1)
        tmpArray[tmpPos++]  = A[i++];
    while (j <= end)
        tmpArray[tmpPos++]  = A[j++];
    for (i = 0; i < length; i++)
        A[begin + i] = tmpArray[begin + i];
}

void merge_sort(int A[], int N)
{
    int tmpArray[N];
    merge_sort(A, tmpArray, 0, N - 1);
}


void merge_sort(int A[], int tmpArray[], int begin, int end)
{
    int center;
    //cout << begin << ' ' << end << endl;
    if (begin < end)
    {
        center = (begin + end) / 2;
        merge_sort(A, tmpArray, begin, center);//at first I wrote center-1 instead of center and leave the two center + 1 as center, this create an infinite loop
        merge_sort(A, tmpArray, center + 1, end);
        merge(A, tmpArray, begin, center + 1, end);
    }
}


void select_sort(int A[], int N)
{
    int i, j;
    int tmp;
    int maxIndex;
    for (i = N - 1; i > 0; i--)
    {
        maxIndex = 0;
        for (j = 0; j <= i; j++)
        {
            if (A[j] > A[maxIndex])
                maxIndex = j;
        }
        tmp = A[i];
        A[i] = A[maxIndex];
        A[maxIndex] = tmp;
    }
}

void test_median3()
{
    int A[] = {4, 2, 3, 8, 9, 7, 6};
    print(A, 7);
    median3(A, 0, 6);
    print(A, 7);
}


int median3(int A[], int left, int right)
{
    int center = (left + right) / 2;
    if (A[left] > A[center])
        swap(&A[left], &A[center]);
    if (A[center] > A[right])
        swap(&A[center], &A[right]);
    if (A[left] > A[center])
        swap(&A[left], &A[center]);
    swap(&A[center], &A[right - 1]);
    return A[right - 1];
}


void quick_sort(int A[], int N)
{
    quick_sort(A, 0, N - 1);
}


void quick_sort(int A[], int left, int right)
{
    int pivot;
    int i, j;
    if (left < right)
    {
        pivot = median3(A, left, right);
        i = left;
        j = right - 1;
        while(i < j)
        {
            while(A[++i] < pivot);
            while(A[--j] > pivot);
            if (i < j)
                swap(&A[i], &A[j]);
        }
        swap(&A[i], &A[right - 1]);
        quick_sort(A, left, i - 1);
        quick_sort(A, i + 1, right);
    }
}
