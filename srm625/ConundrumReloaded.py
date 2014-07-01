

class ConundrumReloaded:

    def min(self, m1, m2):
        if m1 is None and m2 is None:
            return None
        elif m1 is None:
            return m2
        elif m2 is None:
            return m1
        else:
            return min(m1, m2)

    def minimumLiars(self, answers):
        self.answers = answers
        self.last = len(answers)
        a = answers[0]
        r = self.min(self._iter(0, "H", a), self._iter(0, "L", a))
        print ("ans: ", r)
        if r is None:
            return -1
        return r

    def _iter(self, i, state, ans):
        if i == 0:
            self.first_state = state
        if i == self.last:
            if self.first_state == state:
                return 0 if state == "H" else 1
            else:
                return None

        if i == self.last - 1:
            next_ans = self.answers[0]  # dummy
        else:
            next_ans = self.answers[i + 1]
        if (state == "H" and ans == "H") or (state == "L" and ans == "L"):
            next_state = "H"
        else:
            next_state = "L"

        if ans == "?":
            if next_ans == "H" or next_ans == "L":
                r = self.min(self._iter(i + 1, "H", next_ans), self._iter(i + 1, "L", next_ans))
            else:
                r = self._iter(i + 1, "H", next_ans)
        else:
            r = self._iter(i + 1, next_state, next_ans)

        if r is None:  # contraction
            return None
        elif state == "H":
            return r
        else:
            return r + 1


def main():
    c = ConundrumReloaded()
    for s, ans in [("LLH", 1), ("????", 0), ("LHLH?", 2), ("??LLLLLL??", 3), ("LLL", -1)]:
        if not (c.minimumLiars(s) == ans):
            print("%s != %s" % (s, ans))
            break
    else:
        print("OK")

if __name__ == '__main__':
    main()
