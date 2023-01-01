# Link to solutions
https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/submissions/868949140/?envType=study-plan&id=data-structure-ii

# Insights
* using a stack to store indices of left paranthesis and appending then to the result string.
* for right paranthesis, only appending them to result, when length of above stack > 0. also popping from above stack.
* after one complete traversal, remove any pending left paranthesis from the result string.