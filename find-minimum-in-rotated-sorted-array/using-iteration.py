class Solution:
    def findMin(self, nums):
        low = 0
        high = len(nums) - 1
        while low <= high:
            mid = (low+high) // 2

            if nums[mid] > nums[high]:
                low = mid + 1
            elif mid == 0 or nums[mid-1] > nums[mid]:
                return nums[mid]
            else:
                high = mid - 1