str = "ab"

dic = {"a":1, "b":2, "c":3, "d":4}


def position(str):
    res = 0
    length = len(str)
    for index, s in enumerate(str[::-1]):
        res += dic[s] * (4 ** (length - 1 -index))
    return res

print position("ababacd")
