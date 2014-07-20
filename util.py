import os


class L(object):

    def __init__(self, f, new_ext=".csv"):
        base = os.path.basename(f)
        dir = os.path.dirname(f)
        base, ext = os.path.splitext(base)
        self.file = os.path.join(dir, base + new_ext)

        with open(self.file) as f:
            lines = f.read()
            count = 0
            for data in lines.split("\n\n"):
                if data.startswith("#"):
                    continue
                try:
                    rv = self.line(data)
                    print("(%s) => %s" % (count, rv))
                except ValueError, e:
                    print(e)
                count += 1

    def line(self, data):
        raise NotImplemented


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
