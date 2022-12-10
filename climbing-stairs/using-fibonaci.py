class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 1:
            return 1

        one = 1
        two = 1
        res = 0
        for i in range(n-1):
            res = one + two
            two = one
            one = res

        return res

print(Solution().climbStairs(5))