
"""
0 1 2 ... N - 1, N のうち２つを取り出すイメージ
"""

class SumOfPower:
    def findSum(self, a):
        l = len(a)
        result = []
        for i in range(l):
            for j in range(i + 1, l + 1):
                s = sum(a[i: j])
                result.append(s)
        return sum(result)

data = [
    [1, 2],
    [1, 1, 1],
    [3, 14, 15, 92, 65],
    [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
]
for d in data:
    s = SumOfPower()
    print s.findSum(d)
