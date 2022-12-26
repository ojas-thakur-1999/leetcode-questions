# Link to solutions
https://leetcode.com/problems/shortest-path-in-binary-matrix/submissions/865739392/?envType=study-plan&id=algorithm-ii

# Insights
* using BFS here, to iterate over surrounding points == 0, and marking them == 1, once traversed.
* also storing a length covered so far variable with each point added to the queue for BFS
* this works because if we start from the top left corner, then each 0 will have some length associated with it. using a BFS approach, we conver all 0's at a certain length and append all their neighbours with length+1, so it does not matter from where it is being appended, only the length+1 matters.