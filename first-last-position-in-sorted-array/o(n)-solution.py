class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        first = -1
        last = -1
        for i in range(len(nums)):
            if nums[i] == target:
                first = i
                break
        
        if first == -1:
            return [first, last]

        for i in reversed(range(len(nums))):
            if nums[i] == target:
                last = i
                break
        
        return [first, last]
