class Solution:
    def searchRange(self, nums, target):
        leftIdx = self.binarySearchLeft(nums, target, 0, len(nums)-1)
        rightIdx = self.binarySearchRight(nums, target, 0, len(nums)-1)
        return [leftIdx, rightIdx]

    def binarySearchRight(self, nums, target, start, end):
        if end <= start:
            if nums[start] == target:
                return start
            else:
                return -1

        right = -1
        mid = (start+end) // 2
        if target > nums[mid]:
            right = self.binarySearchRight(nums, target, mid+1, end)
        elif target < nums[mid]:
            right = self.binarySearchRight(nums, target, start, mid-1)
        else:
            if nums[mid+1] == target:
                right = self.binarySearchRight(nums, target, mid+1, end)
            else:
                right = mid
        
        return right
    
    def binarySearchLeft(self, nums, target, start, end):
        if end <= start:
            if nums[start] == target:
                return start
            else:
                return -1

        left = -1
        mid = (start+end) // 2
        if target > nums[mid]:
            left = self.binarySearchLeft(nums, target, mid+1, end)
        elif target < nums[mid]:
            left = self.binarySearchLeft(nums, target, start, mid-1)
        else:
            if nums[mid-1] == target:
                left = self.binarySearchLeft(nums, target, mid-1, end)
            else:
                left = mid
        
        return left

