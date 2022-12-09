# Links to solutions
https://leetcode.com/problems/valid-parentheses/submissions/

# Insights
Using list manipulation by manually adding elements to the list was significantly slower than using the existing list functions, like pop() and append(). Also, adding multiple comparisons to check matching parenthesis type, was also slower compared to maintaining a dictionary with the mappings and searching withing its keys.