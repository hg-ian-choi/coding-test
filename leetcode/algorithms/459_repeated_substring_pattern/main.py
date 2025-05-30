class RepeatedSubstringPattern:
    def repeatedSubstringPattern(self, s: str) -> bool:
        if len(s) < 2:
            return False

        return (s[-len(s) + 1 :] + s[: len(s) - 1]).find(s) >= 0


    # Solution
    def solution(self, s: str) -> bool:
        if not str:
            return False

        ss = (str + str)[1:-1]

        return ss.find(str) != -1
