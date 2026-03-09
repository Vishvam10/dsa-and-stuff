from functools import lru_cache

class Solution:
    def minDistance(self, w1: str, w2: str) -> int:

        @lru_cache(None)
        def solve(i, j):

            if i == len(w1):
                return len(w2) - j

            if j == len(w2):
                return len(w1) - i

            if w1[i] == w2[j]:
                return solve(i + 1, j + 1)

            deleteA = 1 + solve(i + 1, j)
            deleteB = 1 + solve(i, j + 1)

            return min(deleteA, deleteB)

        return solve(0, 0)