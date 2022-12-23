class Solution:
    def minSubArrayLen(self, target, nums):
        if target < 0:
            return 0
        len_nums = len(nums)
        start = end = 0
        min_length = len_nums + 1
        curr_window_sum = 0
        while end < len_nums:
            curr_window_sum += nums[end]
            while curr_window_sum >= target:
                curr_window_len = end - start + 1
                min_length = min(min_length, curr_window_len)
                curr_window_sum -= nums[start]
                start += 1
            end += 1
        
        if min_length == len_nums + 1:
            return 0
        
        return min_length