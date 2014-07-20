#! -*- coding: utf-8 -*-
from util import L, memo

"""
同じものを含む順列から、固定数取り出す問題の考え方
--------------------------------------------------

[a1 a2 b]から2つ取り出す場合、
(a1, b)のペアが確定したら
(a2, b)のペアは本来計算しなくてよい

[a1 a2 b1, b2]の場合も同様に、
(a1, b1)と(a1, b2), (a2, b1), (a2, b2)は同一のものとカウントさせたい

10個の要素をもつ順列から2つ取り出して行く場合は、
10C2 * 8C2 ... 2C2
を計算することになる

データの保持の仕方
-------------------
配列から2つ取り除いたものが次の状態になる
ただし、愚直に配列から2つ除くとすると(2つの選び方は問題に依存) ::

    [1, 2, 3, 4, 5] => [1, 2, 3]
                       [2, 3, 4]
                       [3, 4, 5]

上記のように複数のオブジェクトを生成しないといけない。
この配列を作成するコストは非常に高いので、bit列で代用する
visited = 0b10110みたいな感じ
64bitとすれば、50要素の順列程度はintでことが足りる

run1を改良してrunを作成
-----------------------
固定数取り出す場合、同じ状態になる可能性が高いことを利用して、キャッシュするようにした。 ::

    [a,b,c,d,e] => [c,d,e] => [e]
                   [a,b,e] => [e]
                   [a,c,e] => [e]
                   ...

また、同じ要素を含むため必ずbitは左側から立てるようにした
"""


def run(letters):
    letters = sorted(letters)
    length = len(letters)
    chars = sorted(list(set(letters)))

    pairs = []
    for i in range(len(chars) - 1):
        for j in range(i + 1, len(chars)):
            c1 = chars[i]
            c2 = chars[j]
            p = (c1, c2)
            if p not in pairs:
                pairs.append(p)

    def geti(visited, c):
        count = 0
        for l in letters:
            if l != c:
                count += 1
                continue
            else:
                bl = 1 << count
                if bl & visited == 0:  # まだ訪れてない
                    return count
                count += 1
        else:
            return None

    @memo
    def dfs(visited):
        #print("visited %s " % visited)
        if visited ^ ((2 << length - 1) - 1) == 0:
            return [""]

        unused = []
        for i in range(length):
            bi = 1 << i
            if bi & visited == 0:
                unused.append(letters[i])
        else:
            if len(set(unused)) == 1:
                #print("return %s" % unused[0])
                return [unused[0]]

        chars = [""]
        for c1, c2 in pairs:
            i1 = geti(visited, c1)
            i2 = geti(visited, c2)
            if i1 is None or i2 is None:
                continue

            b1 = 1 << i1
            b2 = 1 << i2
            v = visited + b1 + b2

            #import ipdb; ipdb.set_trace()
            chars += dfs(v)
        return chars

    rv = dfs(0)
    return "".join(list(sorted(set(rv))))


def run1(letters):
    """
    同じものを区別しないで、計算するため大変遅い
    """
    length = len(letters)

    def dfs(visited):
        #print("visited %s" % visited)
        if "0" not in bin(visited)[1:]:
            return [""]

        unused = []
        for i in range(length):
            bi = 1 << i
            if bi & visited == 0:
                unused.append(letters[i])
        else:
            if len(set(unused)) == 1:
                return [unused[0]]
        #print("unused %s" % unused)

        chars = [""]
        for i in range(length):
            bi = 1 << i
            if bi & visited != 0:
                continue
            for j in range(length):
                bj = 1 << j
                if bj & visited != 0:
                    continue
                elif i == j:
                    continue
                elif letters[i] == letters[j]:
                    continue
                else:
                    v = visited + bi + bj
                    rv = dfs(v)
                    chars += rv
        return chars
    rv = dfs(0)
    return "".join(list(sorted(set(rv))))


def line(self, data):
    return run(data.strip())

L.line = line
L(__file__)
