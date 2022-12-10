class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        i = 0
        j = len(nums) - 1
        while i < j:
            midIdx = (i + j)//2
            if target == nums[midIdx]:
                return midIdx
            elif target < nums[midIdx]:
                j = midIdx
            else:
                i = midIdx + 1
        
        if target <= nums[j]:
            return j
        
        return j + 1

