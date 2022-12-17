class Solution:
    def threeSum(self, nums):
        nums = self.sort(nums)
        result = []
        already_found = {}
        for i in range(len(nums)):
            arr = nums[0:i] + nums[i+1:len(nums)]
            left = 0
            right = len(arr)-1
            while (left < right):
                if nums[i] + arr[left] + arr[right] < 0:
                    left += 1
                elif nums[i] + arr[left] + arr[right] > 0:
                    right -= 1
                else:
                    key = ""
                    res = ""
                    if nums[i] < arr[left]:
                        key = f"{nums[i]}{arr[left]}{arr[right]}"
                        res = [nums[i], arr[left], arr[right]]
                    elif nums[i] < arr[right]:
                        key = f"{arr[left]}{nums[i]}{arr[right]}"
                        res = [arr[left], nums[i], arr[right]]
                    else:
                        key = f"{arr[left]}{arr[right]}{nums[i]}"
                        res = [arr[left], arr[right], nums[i]]
                    if key not in already_found.keys():
                        already_found[key] = True
                        result.append(res)
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