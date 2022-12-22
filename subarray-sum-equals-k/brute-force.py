class Solution:
	def subarraySum(self, nums, k):
		num_subarrays = 0
		for i in range(len(nums)):
			start = i
			end = i
			while end < len(nums):
				sum = 0
				for j in range(start, end+1):
					sum += nums[j]
				if sum == k:
					num_subarrays += 1
				end += 1
		return num_subarrays
