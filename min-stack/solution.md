# Link to solutions
https://leetcode.com/problems/min-stack/submissions/868924182/?envType=study-plan&id=data-structure-ii

# Insights
* to make all operations O(1), we will store a prev_min value in each node of the stack, so that when this node is popped, we can simple assign the prev_min_value of this node as the min_value of the stack now.