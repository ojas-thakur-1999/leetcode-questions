class Solution:
    def productExceptSelf(self, nums):
        if len(nums) == 0:
            return []
        elif len(nums) == 1:
            return nums

        prefixes = [1]*len(nums)
        suffixes = [1]*len(nums)

        prefixes[0] = 1
        for i in range(1, len(nums)):
            prefixes[i] = prefixes[i-1]*nums[i-1]
        
        for i in range(len(nums)-2, -1, -1):
            suffixes[i] = suffixes[i+1]*nums[i+1]
        
        result = [1]*len(nums)
        for i in range(len(nums)):
            result[i] = prefixes[i]*suffixes[i]
        
        return result
