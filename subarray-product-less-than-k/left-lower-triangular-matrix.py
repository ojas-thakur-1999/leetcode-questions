class Solution:
    def numSubarrayProductLessThanK(self, nums, k):
        dp = [1]*len(nums)
        for i in range(len(nums)):
            dp[i] = [1]*len(nums)
        result = 0
        x = 0
        while x < len(nums):
            y = 0
            while y < x+1:
                if x > 0 and y > 0:
                    dp[x][y] = dp[x][0]*dp[x-1][y-1]
                else:
                    dp[x][y] = nums[x]
                
                if dp[x][y] < k:
                    result += 1
                
                y += 1
            x += 1
        
        return result