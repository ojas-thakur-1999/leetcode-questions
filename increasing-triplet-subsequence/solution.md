# Link to solutions
https://leetcode.com/problems/increasing-triplet-subsequence/submissions/863267151/?envType=study-plan&id=data-structure-ii

# Insights
The more-optimized approach listed here, works on the principle that if we are able to find a sequence (first, second), then we just have to find a number third > second, to complete the triplet. Now, while iterating through the array, we keep looking for first and second which are smaller than given (first, second), so that finding third number becomes easier.