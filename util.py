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
                try:
                    rv = self.line(data)
                    print("(%s) => %s" % (count, rv))
                except ValueError, e:
                    print(e)
                count += 1

    def line(self, data):
        raise NotImplemented
