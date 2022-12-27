class Solution:
    def subsetsWithDup(self, nums):
        nums.sort(key=lambda x: x)
        result = []
        temp = []
        self.subsetsRecursive(nums, temp, result, 0)
        return result
    
    def subsetsRecursive(self, nums, temp, result, idx):
        result.append(temp.copy())
        for i in range(idx, len(nums)):
            if i == idx or nums[i] != nums[i-1]:
                temp.append(nums[i])
                self.subsetsRecursive(nums, temp, result, idx+1)
                temp.pop()

# ans = Solution().subsetsWithDup([1,3,2,3,4,3,5,3])
ans = Solution().subsetsWithDup([1,2,3])
print(len(ans))
print(ans)
