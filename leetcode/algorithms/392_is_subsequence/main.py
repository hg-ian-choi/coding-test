class IsSubsequence:
    def isSubsequence(self, s: str, t: str) -> bool:
        while len(s) > 0:
            index = t.find(s[0])
            if index == -1:
                return False
            t = t[index + 1:]
            s = s[1:]
        return True


    # Solution
    def solution(self, s: str, t: str) -> bool:
        if len(s) > len(t):
            return False

        if len(s) == 0:
            return True

        subsequence = 0
        for i in range(0, len(t)):
            if subsequence <= len(s) - 1:
                print(s[subsequence])
                if s[subsequence] == t[i]:
                    subsequence += 1

        return subsequence == len(s)
