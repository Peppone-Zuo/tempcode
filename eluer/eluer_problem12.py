import re

def get_nth_tranguler(n):
    res = 0
    for i in xrange(1, n + 1):
        res += i
    return res
        

for i in range(1, 10):
    print get_nth_tranguler(i)



def isPrime(n):
    # see http://www.noulakaz.net/weblog/2007/03/18/a-regular-expression-to-check-for-prime-numbers/
    return re.match(r'^1?$|^(11+?)\1+$', '1' * n) == None

for i in range(1, 20):
    print i, isPrime(i)


i = raw_input()
