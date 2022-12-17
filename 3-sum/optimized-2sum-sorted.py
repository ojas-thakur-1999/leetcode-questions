class Solution:
    def threeSum(self, nums):
        nums = self.sort(nums)
        result = []
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            left = i + 1
            right = len(nums)-1
            while (left < right):
                if nums[i] + nums[left] + nums[right] < 0:
                    left += 1
                elif nums[i] + nums[left] + nums[right] > 0:
                    right -= 1
                else:
                    result.append([nums[i], nums[left], nums[right]])
                    left += 1
                    while left < right and nums[left] == nums[left-1]:
                        left += 1

        return result

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