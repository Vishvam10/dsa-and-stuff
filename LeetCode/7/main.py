class Solution:
    def reverse(self, x: int) -> int:
        ans = str(x)[::-1]
        if(ans[-1] == "-") :
            ans = "-" + ans[:-1]
        ans = int(ans)
        if(ans < -2 ** 31 or ans > (2 ** 31) - 1) :
            ans = 0
        return ans