import sys
sys.setrecursionlimit(10**6)


def memo(f):
    cache = {}

    def wrap(*key):
        if key in cache:
            rv = cache[key]
        else:
            rv = f(*key)
            cache[key] = rv
        return rv
    return wrap


def run(a, b, c, d):

    def f(A, B):
        @memo
        def dfs(x, a):
            if a == 0:
                if x == 0:
                    return 1
                else:
                    return 0
            l = []
            for i in range(1, B + 1):
                if 0 <= x - i <= A * B:
                    r = dfs(x - i, a - 1)
                    l.append(r)
            return sum(l) / float(B)

        result = [0] * (A * B + 1)
        for i in range(A, A * B + 1):
            result[i] = dfs(i, A)
        return result

    Alice = f(a, b)
    Bob = f(c, d)

    pw = 0
    for ia in range(a, a * b + 1):
        for ic in range(c, c * d + 1):
            if ia > ic:
                pw += Alice[ia] * Bob[ic]
    if pw <= 0:
        return -1

    r = 0.0
    for ia in range(a, a * b + 1):
        for ic in range(c, c * d + 1):
            if ia > ic:
                r += ia * (Alice[ia] * Bob[ic])

    return r / pw

import os
dir = os.path.dirname(__file__)
fpath = os.path.join(dir, "FixedDiceGameDiv1.csv")
with open(fpath) as f:
    lines = f.read()
    count = 0
    for data in lines.split("\n\n"):
        try:
            a, b, c, d = data.split()
        except:
            pass
        rv = run(int(a), int(b), int(c), int(d))
        print("(%s) => %s" % (count, rv))
        count += 1
