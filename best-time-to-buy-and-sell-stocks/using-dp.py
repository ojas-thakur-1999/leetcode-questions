class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0:
            return 0
        
        max_diff = 0
        max_so_far = 0
        for i in range(1, len(prices)):
            max_diff = max(0, max_diff + prices[i] - prices[i-1])
            max_so_far = max(max_diff, max_so_far)
        
        return max_so_far
