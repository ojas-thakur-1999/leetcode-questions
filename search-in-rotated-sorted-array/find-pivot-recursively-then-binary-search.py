class Solution:
    def search(self, nums, target):
        pivot = self.findPivot(nums, 0, len(nums)-1)
        if pivot > 0:
            arr =  nums[pivot:] + nums[:pivot]
            idx = self.binarySearch(arr, target, 0, len(arr)-1)
            return idx if idx < 0 else (idx + pivot) % (len(nums))
        else:
            return self.binarySearch(nums, target, 0, len(nums)-1)
        
        

    def findPivot(self, nums, start, end):
        if end < start:
            return -1
        
        mid = (start + end) // 2
        if mid > 0 and nums[mid-1] > nums[mid]:
            return mid
        else:
            return max(self.findPivot(nums, start, mid-1), self.findPivot(nums, mid+1, end))

    def binarySearch(self, arr, target, start, end):
        if end < start:
            return -1
        
        mid = (start + end) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            return self.binarySearch(arr, target, mid+1, end)
        else:
            return self.binarySearch(arr, target, start, mid-1)