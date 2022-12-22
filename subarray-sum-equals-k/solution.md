# Link to solutions
https://leetcode.com/problems/subarray-sum-equals-k/submissions/863610955/?envType=study-plan&id=data-structure-ii

# Insights
Looping through the array, maintain a dictionary of all different subarray sums (from index 0 to i), till now and their counts. Also keep a pointer for previous sum. Calculate current sum by adding current element to previous sum. If current sum - target exists in dictionary, then append the no of found subarrays by the map value. If not, then store this subarray sum in map.