# Link to solutions
https://leetcode.com/problems/subarray-product-less-than-k/submissions/?envType=study-plan&id=algorithm-ii

# Insights
* brute force approach - making a lower triangular matrix by identifying the relation in contiguous sub-array products
* sliding window approach - keep 2 pointers, start and end, which enclose the window. keep incrementing end, as long as the subarray product start-end is less than k, and keep on adding new subarrys ending at end. If at any point, subarray produce is >= k, then keep incrementing start by divinding the product by nums[start] till the product is less than k. Now add the subarrays ending at end and then increment end.
* Also, removing redundant code by minimising conditionals works significantly faster.