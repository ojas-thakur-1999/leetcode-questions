class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # DNF Algorithm - however, does not maintain the order
        """
        low = 0
        high = len(nums)-1
        while low < high:
            if nums[low] == 0 and nums[high] != 0:
                nums[low] = nums[high]
                nums[high] = 0
                high -= 1
            low += 1
        """
        # Maintaining the order as well
        i = j = 0
        while i < len(nums):
            if nums[i] == 0:
                i += 1
            else:
                temp = nums[i]
                nums[i] = nums[j]
                nums[j] = temp
                i += 1
                j += 1