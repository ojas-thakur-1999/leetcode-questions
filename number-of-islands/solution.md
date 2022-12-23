# Link to solutions
https://leetcode.com/problems/number-of-islands/submissions/864295786/?envType=study-plan&id=algorithm-ii

# Insights
* We can approach this problem by both DFS and BFS approach. 
* When at a node == '1', set it to '0' and do a DFS on all 4 adjacent nodes. This way, all first island nodes will be marked 0 in the first DFS. Then when we arrive at a  previously unvisited 1 node, then another DFS will start.