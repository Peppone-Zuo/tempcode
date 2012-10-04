#include <iostream>
#include <math.h>
#include <math.h>

using namespace std;

const int MAX_TRY = 10000;



int main(void) {
    double res = 0.0;
    double num = 5.0 / 6.0;
    for (int i = 2; i < MAX_TRY; i++) {
        res += pow(num, i);
    }
    cout << res << endl;
    return 0;
}
