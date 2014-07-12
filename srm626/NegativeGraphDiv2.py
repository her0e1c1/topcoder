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


def run(N, s, t, weight, charges):
    INF = 2 ** 31
    dist = [[INF] * N for _ in range(N)]
    # for i in range(N):
    #     dist[i][i] = 0

    @memo
    def path(u, v, k):
        # Floyd-Warshall algorithm
        if k == -1:
            if u == v:
                return 0
            l = []
            for i in range(len(s)):
                if s[i] - 1 == u and t[i] - 1 == v:
                    l.append(weight[i])
            if l:
                return min(l)
            else:
                return INF

        p1 = path(u, v, k - 1)
        p2 = path(u, k, k - 1) + path(k, v, k - 1)
        return min([p1, p2])

    for i in range(N):
        for j in range(N):
            dist[i][j] = path(i, j, N - 1)
    #print ("dist: ", dist)

    @memo
    def dfs(c, n):
        if c == 0:
            return dist[n][N - 1]

        paths = [dfs(c - 1, n)]
        for i in range(len(s)):
            u = s[i] - 1
            v = t[i] - 1
            w = -1 * weight[i]
            p = dist[n][u] + w + dfs(c - 1, v)
            paths.append(p)

        return min(paths)

    return dfs(charges, 0)


def arr(s):
    return [int(x) for x in s[1: -1].split(",")]


import os
dir = os.path.dirname(__file__)
fpath = os.path.join(dir, "NegativeGraphDiv2.csv")
with open(fpath) as f:
    lines = f.read()
    count = 0
    for data in lines.split("\n\n"):
        try:
            N, s, t, weight, charges = data.split()
            rv = run(int(N), arr(s), arr(t), arr(weight), int(charges))
            print "(%s) => %s" % (count, rv)
        except:
            pass
        count += 1
