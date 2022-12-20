class Solution:
    def findMin(self, nums):
        def findPivotRecursive(nums, start, end):
            if start > end:
                return -1
            
            # pivot in start
            if start > 1 and nums[start] < nums[start-1]:
                return start
            
            mid = (start + end) // 2

            # pivot in middle
            if mid > 0 and nums[mid] < nums[mid-1]:
                return mid

            # pivot in left half
            if nums[start] > nums[mid]:
                return findPivotRecursive(nums, start, mid-1)
            # pivot in right half
            elif nums[mid] > nums[end]:
                return findPivotRecursive(nums, mid+1, end)
            # pivot not in this range
            else:
                return -1

        if len(nums) == 0:
            return 0
            
        pivot = findPivotRecursive(nums, 0, len(nums)-1)
        if pivot < 0:
            return nums[0]
        else:
            return nums[pivot]