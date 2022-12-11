class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        counts = {}
        for i in nums:
            if i not in counts.keys():
                counts[i] = 1
            else:
                counts[i] += 1
        
        foundNum = 0
        for i in nums:
            if counts[i] == 1:
                foundNum = i
                break
        
        return foundNum