# Link to solutions
https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/submissions/865725307/?envType=study-plan&id=algorithm-ii

# Insights
* Here we are doing level order traversal. To do this, we need an extra node outside, which points to the level header.
* We will solve this one level at a time, assuming that next pointers for this level have been populated. Then it is simply a matter of moving along the next pointers for this level to move in a BFS manner and populate the next pointers of the next level.