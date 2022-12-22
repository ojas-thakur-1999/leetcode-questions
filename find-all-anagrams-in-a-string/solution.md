# Link to solutions
https://leetcode.com/problems/find-all-anagrams-in-a-string/submissions/?envType=study-plan&id=algorithm-ii

# Insights
* One approach is the brute force one, to check for anagrams starting form the first index going forward. Complexity is O(M*N)
* Using a dict to keep track of alphabets in current sliding window as well as in s2. Also, checking if removed element matches added element and keeping track of whether previous one was an anagram.