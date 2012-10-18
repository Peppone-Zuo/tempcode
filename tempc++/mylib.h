namespace zspace
{
    template <typename elemtype>
    elemtype max(const elemtype &a, const elemtype &b)
    {
        return a > b ? a : b;
    }

    template <typename elemtype>
    elemtype swap(elemtype &a, elemtype &b)
    {
        elemtype tmp;
        tmp = a;
        a = b;
        b = tmp;
    }

    template <typename elemtype>
    elemtype abs(const elemtype &a)
    {
        return a > 0 ? a : -1 * a;
    }
}
