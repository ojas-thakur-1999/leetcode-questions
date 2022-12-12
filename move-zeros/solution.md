# Link to solutions
https://leetcode.com/problems/move-zeroes/submissions/

# Insights
One brute force algorithm to replace the nearest non-zero number with zero if we get a zero while iterating the array. Another approach is to keep two pointers one for moving the array forward and one for keeping track of the first zero position, so that it can be swapped with the non-zero number found by the first pointer.