#include <iostream>
using namespace std;

int size(int a[][4])
{
    cout << sizeof(a) << endl;
}


int main(void)
{
    int i = 0;

    char *p = new char[20];
    int ip[3][4];
    size(ip);

    for (; i< 10;)
    {
        cout << i << endl;
        switch (i) 
        {
            case 0:
            case 1:
            case 2:
            case 3:
                i++;
            default:
                continue;
            case 4:
                cout << 444 << endl;
                i++;
                break;
        }
        break;
    }

    return 0 ;
}                          
