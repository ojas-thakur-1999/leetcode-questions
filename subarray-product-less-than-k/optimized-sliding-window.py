class Solution:
    def numSubarrayProductLessThanK(self, nums, k):
        if k <= 1:
            return 0
        start = end = no_of_subarrays = 0
        product = 1
        len_nums = len(nums)
        while end < len_nums:
            product = product*nums[end]
            while product >= k:
                product = product / nums[start]
                start = start + 1
            no_of_subarrays += 1 + end - start
            end = end + 1
        
        return no_of_subarrays
