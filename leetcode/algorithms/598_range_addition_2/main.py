from typing import List


class RangeAdditionII:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        minM: int = m
        minN: int = n

        for op in ops:
            minM = min(minM, op[0])
            minN = min(minN, op[1])

        return minM * minN


    # Solution
    def solution(self, m: int, n: int, ops: List[List[int]]) -> int:
        if not ops:
            return m * n

        return min(op[0] for op in ops) * min(op[1] for op in ops)
