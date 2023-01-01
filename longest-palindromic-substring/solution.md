# Link to solutions
https://leetcode.com/problems/longest-palindromic-substring/submissions/?envType=study-plan&id=data-structure-ii

# Insights
* using the brute force method by checking for longest substring from the biggest size, using sliding window (o(n^3))
* using brute force approach with memoization to store already calculated palindrome substrings (still o(n^3))
* making an occurence matrix and find crosses in this matrix (o(n^2))
* finding longest cross diagonal in occurence matrix (o(n^2))
* using brute force by checking longest palindrome centered at an index (o(n^2))
* memoization not applicable in above problem because we are always shifting the centre of the palindrome and hence, there wont be any previously calculated values.