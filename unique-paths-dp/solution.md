# Link to solutions
https://leetcode.com/problems/unique-paths/submissions/?envType=study-plan&id=algorithm-ii

# Insights
* this problem is similar to combination of (n-1) and (m-1) items. then answer is (n-1 + m-1)! / (n-1)! * (m-1)!
* however, above problem runs into integer overflow.
* another approach is recursion, using a memo_array
* dp approach o(m*n) -> make a dp array, dp[i][j] = dp[i-1][j] + dp[i][j-1]