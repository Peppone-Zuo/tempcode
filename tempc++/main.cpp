#include <malloc.h>
#include <iostream>
#include <cstring>
using namespace std;


int main() {
    int ii = 0;
    int iii = 1;
    int &i = ii;
    cout << "the reference is: " << i << endl;
    i = iii;
    cout << i;
    cout << "the reference is: " << i << endl;
    cout << "the value of ii is: " << ii << endl;
    return 0;
}
