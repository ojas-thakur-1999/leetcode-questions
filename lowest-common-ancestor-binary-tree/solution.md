# Link to solutions
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/871261881/?envType=study-plan&id=data-structure-ii

# insights
* one approach is to find ancestors of both nodes separately and then find the latest common ancestor from these 2 vectors.
* another approach is checking occurence of both nodes in a particular subtree
* if a subtree has both nodes, return current node
* if it has only one node, return that node
* if it has no node, return null