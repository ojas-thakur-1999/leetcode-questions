class Solution():
    def search(self, nums, target):
        def searchRotated(nums, target, start, end):
            if end < start:
                return -1
            
            mid = (start + end) // 2

            if target == nums[mid]:
                return mid
            
            # check position of pivot
            if nums[mid] >= nums[start]:
                if target >= nums[start] and target <= nums[mid]:
                    return searchRotated(nums, target, start, mid-1)
                else:
                    return searchRotated(nums, target, mid+1, end)
            else:
                if target >= nums[mid] and target <= nums[end]:
                    return searchRotated(nums, target, mid+1, end)
                else:
                    return searchRotated(nums, target, start, mid-1)

        return searchRotated(nums, target, 0, len(nums)-1)