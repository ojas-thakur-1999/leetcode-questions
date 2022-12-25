# Link to solutions
https://leetcode.com/problems/subtree-of-another-tree/submissions/?envType=study-plan&id=algorithm-ii

# Insights
* Using the normal recursive solution would be fine if all node values were unique. iterating through both trees, we would check for the node values and left right subtrees.
* We can use a DFS type approach by checking all nodes if they are equal to the given subtree.
* Last method is to serialize both the trees in a standard way () and then check if one is the substring of the other.