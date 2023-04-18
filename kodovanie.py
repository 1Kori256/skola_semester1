import math, sys, functools

@functools.cache
def is_prime(n):
    if(n <= 3):
        return True
     
    if(n % 2 == 0 or n % 3 == 0):
        return False
     
    for i in range(5, int(math.sqrt(n) + 1), 6):
        if(n % i == 0 or n % (i + 2) == 0):
            return False
     
    return True


def factorization(n):
    div = 2
    ans = [0]
    while div <= n:
        if n % div == 0:
            ans[-1] += 1
            n = n / div
        else:
            div += 1
            while not is_prime(div):
                div += 1
            ans.append(0)
    return iter(ans)
    

def solve(n):
    if n == 0: return "."
    if n == 1: return "()"
    
    final_str = "("
    for i in factorization(n):
        final_str += solve(i)
    final_str += ")"
    return final_str

for n in map(int, sys.stdin):
    print(solve(n), file=sys.stdout)

# uf
# ! pozor
# ? netusim nic
# TODO: makaj
# * DOLEZITE
# // JE TO  TAK