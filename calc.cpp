#include <iostream>
#include "mylib.h"

//template <typename elemtype>
//void swap(elemtype &a, elemtype &b)
//{
//    elemtype tmp;
//    tmp = a;
//    a = b;
//    b = tmp;
//}
//
//
//template <typename elemtype>
//elemtype max(const elemtype &a, const elemtype &b)
//{
//    return a > b ? a : b;
//}
//
//template <typename elemtype>
//elemtype abs(const elemtype &a)
//{
//    return a > 0 ? a : -1 * a;
//}  


using namespace std;


int main(void)
{
    int a = 1;
    int b = 2;
    cout << a << b << endl;

    a = -1;
    cout << a << endl;
    cout << abs(a) << endl;
    return 0 ;
}
