#include <iostream>
#include "mylib.h"
using namespace std;
 

int main(void)
{
    int a = -1, b = 0;
    cout << a << " " << b << endl;
    cout << zspace::abs(a) << endl;
    cout << a << " " << b << endl;
    zspace::swap(a, b);
    cout << a << " " << b << endl;
    cout << zspace::max(a, b) << endl;
    return 0 ;
}                          

