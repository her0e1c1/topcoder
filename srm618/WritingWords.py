
def write(word):
    return sum([ord(a) - ord("A") + 1 for a in word])

assert write("A") == 1
assert write("ABC") == 6
assert write("VAMOSGIMNASIA") == 143
assert write("TOPCODER") == 96
assert write("SINGLEROUNDMATCH") == 183
assert write("ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ") == 1300

