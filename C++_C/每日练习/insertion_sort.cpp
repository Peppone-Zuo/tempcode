#include <iostream>
using namespace std;



void insertion_sort(int A[], int N);
const int size = 10;

void print(int A[], int N);

int main(void)
{
    int i;
    int A[size];
    
    for (i = 0; i < size; i++)
    {
        A[i] = i;
    }
    print(A, size);
    insertion_sort(A, size);
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


