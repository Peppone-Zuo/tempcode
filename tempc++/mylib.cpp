//template <typename elemtype>
//elemtype abs2(elemtype a)
//{
//    return a > 0 ? a : -1 * a;
//}

template <>
int abs2<int>(int a)
{
    return a > 0 ? a : -1 * a;
}

//template int abs2<int>(int a);
