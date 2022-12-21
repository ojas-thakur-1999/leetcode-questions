class Solution:
    def increasingTriplet(self, nums):
        first = 0
        second = 0
        for i in range(len(nums)):
            if nums[i] > nums[second] and nums[second] > nums[first]:
                return True

            if nums[i] < nums[first]:
                first = i
            
            if first < len(nums)-1:
                min_diff = nums[first+1] - nums[first]
                second = first+1
                for j in range(first+1, i+1):
                    if nums[j] - nums[first] > 0 and nums[j] - nums[first] < min_diff:
                        second = j
            
        return False