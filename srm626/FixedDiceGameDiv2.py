#! -*- coding:utf-8 -*-
"""
1e-9のような値を答えるときはPythonだと計算が合わなくなる可能性あり
440 / 5.0 =  7.999999999999999 (not 8.0)
ただし、32bitと64bitでも結果が異なる
"""


class FixedDiceGameDiv2:
    def getExpectation(self, a, b):
        # 小数で宣言する
        count = 0.0
        rv = 0.0
        for i in range(1, b + 1):
            for j in range(i + 1, a + 1):
                rv += j
                count += 1
        print ("%s / %s" % (rv, count))
        return rv / count
data = [
    [2, 2],
    [4, 2],
    [3, 3],
    [11, 13]
]

for d in data:
    f = FixedDiceGameDiv2()
    print(f.getExpectation(*d))
