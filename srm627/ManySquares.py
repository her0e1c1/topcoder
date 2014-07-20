from util import L


def run(sticks):
    return sum([sticks.count(i) / 4 for i in set(sticks)])


def line(self, data):
    d = data[1:-1].split(",")
    d = [int(i) for i in d]
    return run(d)


L.line = line
L(__file__)
