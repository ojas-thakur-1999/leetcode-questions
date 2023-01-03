# Link to solutions
https://leetcode.com/problems/longest-increasing-subsequence/submissions/870424549/?envType=study-plan&id=algorithm-ii

# Insights
* first tried the recursive solution, by calculating the length of a substring ending at a particular index
* then converted this to iterative dp problem (however, still n^2)
* to convert to n*logn, using greedy solution, in which we maintain a subarry of increasing numbers, and as long as the next number is greater than the greatest number, then keep adding it to the subarray. however, if we face a number smaller than the top of subarray, then we find that number which is just >= the current number from the subarray and replace it with current number.