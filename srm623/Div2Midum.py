import math


def run(R, T, Vrat, Vcat):
    if Vrat >= Vcat:
        return -1

    dist = T * Vrat
    limit = R * math.pi
    if limit <= dist:
        dist = limit
    return dist / float(Vcat - Vrat)

print(run(10, 1, 1, 1))
print(run(10, 1, 1, 2))
print(run(10, 1, 2, 1))
print(run(1000, 1000, 1, 1000))
print(run(1, 1000, 1, 2))
