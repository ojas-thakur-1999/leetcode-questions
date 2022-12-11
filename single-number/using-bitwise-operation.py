class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        count = 0
        for num in nums:
            count = count ^ num
        return count