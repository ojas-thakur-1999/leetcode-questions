# Link to solutions
https://leetcode.com/problems/longest-common-subsequence/submissions/860081054/

# Insights
* First approach was using recursion (while iterating over both strings, check if both characters match, then increment both and add one to maxLength, else return max of one displaced strings). This recursive solution is very slow and computes subproblems multiple times. 
* To make it fast, we can use memoization, by maintaining a matrix which stores whether we have already copmuted a[i][j]. This is the top-down DP approach.
* Lastly, we observe that a[i][j] only depends on a[i+1][j+1], a[i][j+1], a[i+1][j]. Which means we can start from reverse end of the matrix and keep filling till a[0][0]. This is the bottom-up DP approach.
* DP can be applied in any problem where we see that one subproblem is being re-computed. In this case, we first had to identify the simple recursive solution, from which we got the subproblems which were being repeated and we could make the DP matrix.