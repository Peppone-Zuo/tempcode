#include <iostream>
using namespace std;

void bubble_sort(int A[], int N);
void int2str(int a, char *p);
void print(int A[], int N);

const int size = 10;
int A[] = {4, 2, 3, 8, 7, 5, 9, 0, 1, 6};
char str[10];

int main()
{
    print(A, size);
    bubble_sort(A, size);
    print(A, size);
    int2str(0, str);
    cout << str << endl;
    return 0;
}

void int2str(int a, char *p)
{
    int tmp;
    char ctmp;
    char *q = p;
    if (a == 0)
        *p++ = '0';
    else if (a < 0)
    {
        *p++ = '-';
        a = -a;
    }
    while (a > 0)
    {
        tmp = a % 10;
        *p++ = tmp + '0';
        a /= 10;
    }
    *p-- = '\0';
    if (*q == '-')
        q++;
    while (q < p)
    {
        ctmp = *p;
        *p = *q;
        *q = ctmp;
        q++;
        p--;
    }
    
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

