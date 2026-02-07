from functools import cmp_to_key


class Solution:
    def largestNumber(self, arr: List[int]) -> str:
        def compare(a: str, b: str) -> int:
            if a + b > b + a:
                return -1
            elif a + b < b + a:
                return 1
            else:
                return 0

        nums = list(map(str, arr))
        nums.sort(key=cmp_to_key(compare))

        return "0" if nums[0] == "0" else "".join(nums)
