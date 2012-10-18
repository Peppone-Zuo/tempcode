#include <iostream>
using namespace std;



void insertion_sort(int A[], int N);
void select_sort(int A[], int N);
void shell_sort(int A[], int N);
void bubble_sort(int A[], int N);
void merge_sort(int A[], int N);
void merge_sort(int A[], int tmpArray[], int left, int right);
void merge(int A[], int tmpArray[], int left, int center, int right);
void quick_sort(int A[], int left, int right);




const int size = 10;

void print(int A[], int N);

int main(void)
{
    int i;
    int A[size] = {4, 2, 3, 9, 8, 5, 1, 7, 6, 11};
    
    print(A, size);
    //insertion_sort(A, size);
    //shell_sort(A, size);
    //bubble_sort(A, size);
    //merge_sort(A, size);
    //insertion_sort(A, size);
    //select_sort(A, size);
    quick_sort(A, 0, size - 1);
    print(A, size);

    return 0;
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


void shell_sort(int A[], int N)
{
    int gap, tmp;
    int i, j;
    for (gap = N / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < N; i++)
        {
            tmp = A[i];
            for (j = i; j >= gap && A[j - gap] > tmp; j -= gap)
                A[j] = A[j - gap];
            A[j] = tmp;
        }
    }
}


void bubble_sort(int A[], int N)
{
    int i, j;
    int tmp;
    for (i = N - 1; i > 1; i--)
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

void merge(int A[], int tmpArray[], int left, int center, int right)
{
    int leftBound = center - 1;
    int i, j, k;
    i = left;
    j = center;
    k = left;
    while (i <= leftBound && j <= right)
    {
        if (A[i] < A[j])
            tmpArray[k++] = A[i++];
        else
            tmpArray[k++] = A[j++];
    }
    while (i <= leftBound)
        tmpArray[k++] = A[i++];
    while (j <= right)
        tmpArray[k++] = A[j++];
    i = left;
    while (i <= right)
        A[i++] = tmpArray[i++];
}

void merge_sort(int A[], int N)
{
    int tmpArray[N];
    merge_sort(A, tmpArray, 0, N - 1);
}

void merge_sort(int A[], int tmpArray[], int left, int right)
{
    int center = (left + right) / 2;
    if (left < right)
    {
        merge_sort(A, tmpArray, left, center);
        merge_sort(A, tmpArray, center + 1, right);
        merge(A, tmpArray, left, center + 1, right);
    }
}

void insertion_sort(int A[], int N)
{
    int i, j;
    int tmp;
    for (i = 1; i < N; i++)
    {
        tmp = A[i];
        for (j = i; j > 0 && A[j - 1] > tmp; j--)
            A[j] = A[j - 1];
        A[j] = tmp;
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


void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
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

