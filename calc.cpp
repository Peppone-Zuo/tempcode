#include <iostream>

using namespace std;
 

namespace zuo{
    int abs1(const int &a);
    template <typename elemtype>
    elemtype abs(elemtype a);
//    {
//        return a > 0 ? a : -1 * a;
//    }
}

//template <typename elemtype>
//elemtype abs(const elemtype &a)
//{
//    return a > 0 ? a : -1 * a;
//}




int main(void)
{
    int a = -1;
    cout << a << endl;
    cout << zuo::abs1(a) << endl;
    cout << zuo::abs(a) << endl;
    return 0 ;
}                          

namespace zuo
{
    template <typename elemtype>
    elemtype abs(elemtype a)
    {
        return a > 0 ? a : -1 * a;
    }
}


//    int abs1(const int &a)
//    {
//        return a > 0 ? a : -1 * a;
//    }
