class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        lenNums = len(nums)
        i = 0
        while i < lenNums:
            if nums[i] == 0:
                foundNonZero = False
                for j in range(i+1, lenNums):
                    if nums[j] != 0:
                        foundNonZero = True
                        nums[i] = nums[j]
                        nums[j] = 0
                        break
                if not foundNonZero:
                    break
            i += 1
