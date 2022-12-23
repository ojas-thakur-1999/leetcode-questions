class Solution:
    def numSubarrayProductLessThanK(self, nums, k):
        no_subarrays = 0
        start = 0
        end = 0
        product = 1
        while end <= len(nums):
            product = nums[end]*product
            if product < k:
                no_subarrays += 1 + end-start
                end += 1
            else:
                while start <= end and product >= k:
                    product = product / nums[start]
                    start += 1
                no_subarrays += 1 + end-start
                end += 1

        return no_subarrays