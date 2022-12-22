class Solution:
	def subarraySum(self, nums, k):
		if len(nums) == 0:
			return 0

		no_subarrays_found = 0
		found_subarray_sums = {
			0: 1
		}
		prev_subarray_sum = 0
		for i in range(0, len(nums)):
			curr_sum = prev_subarray_sum + nums[i]
			
			if curr_sum - k in found_subarray_sums.keys():
				no_subarrays_found += found_subarray_sums[curr_sum-k]

			if curr_sum not in found_subarray_sums.keys():
				found_subarray_sums[curr_sum] = 1
			else:
				found_subarray_sums[curr_sum] += 1

			prev_subarray_sum = curr_sum

		return no_subarrays_found
