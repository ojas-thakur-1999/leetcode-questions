# Link to solutions
https://leetcode.com/problems/palindrome-linked-list/submissions/

# Insights
If length of list was known beforehand, then problem would have been solved in a single traversal. Here, we are storing all node values in a list and then equating the values equidistant from both ends. Another solution is to generate 2 pointers, one for the reversed first half of the list, one for the second half of the list. Then we can keep doing next and matching the values, till we conver all elements of the list.