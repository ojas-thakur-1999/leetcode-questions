# Link to solutions
https://leetcode.com/problems/single-number/submissions/858228888/

# Insights
One trivial solution is to maintain a dictionary of how many times a particular number has appeared. Another approach is based on the pattern of given input numbers. Here, we need to identify the single element which is not in a pair. So we need some property which is different for a pair of numbers as compared to a single number. We can use bitwise XOR. Since (A ^ A = 1), if we take XOR of all numbers, all pairs will get cancelled out and only the single number will remain.