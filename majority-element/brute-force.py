class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        occurences = {}
        for num in nums:
            if num not in occurences.keys():
                occurences[num] = 1
            else:
                occurences[num] += 1
        
        thresh = len(nums) // 2
        for num in nums:
            if occurences[num] > thresh:
                return num
        
        return -1