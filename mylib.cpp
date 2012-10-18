//    template <typename elemtype>
//    void swap(elemtype &a, elemtype &b)
//    {
//        elemtype tmp;
//        tmp = a;
//        a = b;
//        b = tmp;
//    }
//
//
//    template <typename elemtype>
//    elemtype max(const elemtype &a, const elemtype &b)
//    {
//        return a > b ? a : b;
//    }
//
namespace zuo
{
    template <typename elemtype>
    elemtype abs(elemtype a)
    {
        return a > 0 ? a : -1 * a;
    }

    int abs1(const int &a)
    {
        return a > 0 ? a : -1 * a;
    }
}
