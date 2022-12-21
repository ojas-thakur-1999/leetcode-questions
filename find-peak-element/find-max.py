class Solution:
    def findPeakElement(self, nums):
        if len(nums) == 1:
            return 0

        start = 0
        end = len(nums) - 1
        while start <= end:
            mid = (start + end) // 2
            if (mid == 0 and nums[mid] > nums[mid+1]):
                return mid
            elif (mid == len(nums)-1 and nums[mid] > nums[mid-1]):
                return mid
            elif (nums[mid] > nums[mid+1] and nums[mid] > nums[mid-1]):
                return mid
            elif mid > 0 and nums[mid-1] > nums[mid]:
                end = mid - 1
            elif mid < len(nums)-1 and nums[mid+1] > nums[mid]:
                start = mid + 1
        
        return -1