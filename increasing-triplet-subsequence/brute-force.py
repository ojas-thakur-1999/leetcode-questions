class Solution:
    def increasingTriplet(self, nums):
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if nums[j] > nums[i]:
                    for k in range(j+1, len(nums)):
                        if nums[k] > nums[j]:
                            return True
        return False