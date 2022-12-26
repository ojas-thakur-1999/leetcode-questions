class Solution:
    def subsets(self, nums):
        return self.subsetsRecursive(nums, len(nums)-1)

    def subsetsRecursive(self, nums, idx):
        if idx == 0:
            return [[], [nums[0]]]
        
        subsets = self.subsetsRecursive(nums, idx-1)
        len_subsets = len(subsets)
        for i in range(len_subsets):
            temp_subset = subsets[i].copy()
            temp_subset.append(nums[idx])
            subsets.append(temp_subset)
        
        return subsets