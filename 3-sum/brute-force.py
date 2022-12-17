class Solution:
    def threeSum(self, nums):
        result = []
        already_found = {}
        for i in range(len(nums)):
            two_sums = self.twoSum(nums, 0-nums[i], i)
            for two_sum in two_sums:
                sample = []
                if nums[i] < two_sum[0]:
                    sample = [nums[i], two_sum[0], two_sum[1]]
                elif nums[i] < two_sum[1]:
                    sample = [two_sum[0], nums[i], two_sum[1]]
                else:
                    sample = [two_sum[0], two_sum[1], nums[i]]
                
                key = str(sample[0]) + str(sample[1]) + str(sample[2])
                if key not in already_found.keys():
                    result.append([sample[0], sample[1], sample[2]])
                    already_found[key] = True
        
        return result

    def twoSum(self, nums, target, excluded_index):
        result = []
        already_found = {}
        for i in range(0, excluded_index, 1):
            new_target = target - nums[i]
            for j in range(0, i, 1):
                if nums[j] == new_target:
                    self.checkExistingTwoSum(already_found, result, nums[i], nums[j])
            
            for j in range(i+1, excluded_index, 1):
                if nums[j] == new_target:
                    self.checkExistingTwoSum(already_found, result, nums[i], nums[j])
        
        for i in range(excluded_index+1, len(nums), 1):
            new_target = target - nums[i]
            for j in range(excluded_index+1, i, 1):
                if nums[j] == new_target:
                    self.checkExistingTwoSum(already_found, result, nums[i], nums[j])
            
            for j in range(i+1, len(nums), 1):
                if nums[j] == new_target:
                    self.checkExistingTwoSum(already_found, result, nums[i], nums[j])
        
        return result
    
    def checkExistingTwoSum(self, already_found, result, numi, numj):
        key = ""
        res = []
        if numi < numj:
            key = str(numi) + str(numj)
            res = [numi, numj]
        else:
            key = str(numj) + str(numi)
            res = [numj, numi]
        
        if key not in already_found:
            result.append(res)
            already_found[key] = True

        return