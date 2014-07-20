#! -*- coding: utf-8 -*-
from util import L, memo

"""
グラフのパスである経路を覚えておく必要がある。
そうした場合はBinary Indexed Treeがよい。
"""


def run(A, B, V, K):
    N = len(A)
    INF = 2 * 32

    def getinv(u):
        count = 0
        for i in range(N):
            if not visited[u]:
                continue
            if V[i] > V[u]:
                count += 1
        return count

    def dfs(u):
        inv0 = [INF]
        for i in range(N):
            v = B[i]
            if A[i] != u:
                continue
            elif visited[v]:
                continue
            inv1 = getinv(v)
            visited[v] = True
            import ipdb; ipdb.set_trace()
            inv2 = dfs(v)
            inv0.append(inv1 + inv2)
            visited[v] = False
        return min(inv0)

    inv = []
    for i in range(N):
        visited = [False] * K
        visited[i] = True
        inv.append(dfs(i))
    return min(inv)


def line(self, data):
    A, B, V, K = data.split()

    def l(a):
        return [int(i) for i in a[1: -1].split(",")]
    rv = run(l(A), l(B), l(V), int(K))
    return rv


L.line = line
L(__file__)
