import random
from random import randint

N = 1000

def simulate(N):
    K = 0
    ###insert your code here###
    for _ in range(N):
        car_pos = randint(1, 3)
        guess = randint(1, 3)
        show = random.choice([x for x in (1, 2, 3) if x != car_pos and x != guess])
        new_guess = set([1, 2, 3])
        new_guess.remove(guess)
        new_guess.remove(show)
        if car_pos in new_guess:
            K += 1
    return float(K) / float(N)

print simulate(N)

