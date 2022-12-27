class Solution:
    def subsetsWithDup(self, nums):
        nums = self.sort(nums)
        repeat_arr = [0]*len(nums)
        curr_repeat_idx = 0
        for i in range(1, len(nums)):
            if nums[i] == nums[i-1]:
                curr_repeat_idx += 1
                repeat_arr[i] += curr_repeat_idx
            else:
                curr_repeat_idx = 0
        
        return self.subsetsRecursive(nums, repeat_arr, len(nums)-1)

    def subsetsRecursive(self, nums, repeat_arr, idx):
        if idx == 0:
            return [[], [nums[idx]]]
        
        prev_subsets = self.subsetsRecursive(nums, repeat_arr, idx-1)
        prev_len = len(prev_subsets)
        
        if repeat_arr[idx] > 0:
            for i in range(prev_len):
                temp = prev_subsets[i].copy()
                found_one = False
                for j in range(len(temp)):
                    if temp[j] == nums[idx]:
                        found_one = True
                
                if found_one:
                    del(temp)
                else:
                    for j in range(repeat_arr[idx]+1):
                        temp.append(nums[idx])
                    prev_subsets.append(temp)
        else:
            for i in range(prev_len):
                temp = prev_subsets[i].copy()
                temp.append(nums[idx])
                prev_subsets.append(temp)
        
        return prev_subsets  

    def sort(self, arr):
        if len(arr) == 0:
            return []
        elif len(arr) == 1:
            return arr
        
        mid = len(arr) // 2
        left = self.sort(arr[:mid])
        right = self.sort(arr[mid:])
        return self.merge(left, right)
    
    def merge(self, arr1, arr2):
        len_arr1 = len(arr1)
        len_arr2 = len(arr2)
        i = 0
        j = 0
        res = []
        while i < len_arr1 or j < len_arr2:
            if i == len_arr1:
                res.append(arr2[j])
                j += 1
                continue
            elif j == len_arr2:
                res.append(arr1[i])
                i += 1
                continue
            
            if arr1[i] < arr2[j]:
                res.append(arr1[i])
                i += 1
            else:
                res.append(arr2[j])
                j += 1
        return res


ans = Solution().subsetsWithDup([1,3,2,3,4,3,5,3])
ans = Solution().subsetsWithDup([1,2,2])
print(len(ans))