class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profitMax = 0
        for i in range(len(prices)):
            for j in range(i+1, len(prices)):
                profit = prices[j] - prices[i]
                profitMax = max(profitMax, profit)
        return profitMax