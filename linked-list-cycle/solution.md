# List of solutions
https://leetcode.com/problems/linked-list-cycle/submissions/

# Insights
Using dictionary keys is much faster than maintaining an array manually and checking for value in array. Also, another solution can be to change the next address of all nodes to some placeholder (we can also change the values in them to some place-holder text). However, this solution will destroy the original linked list, so that should be noted.