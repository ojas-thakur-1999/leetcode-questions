# Link to solutions
https://leetcode.com/problems/surrounded-regions/submissions/865784824/?envType=study-plan&id=algorithm-ii

# Insights
using BFS approach and a visited array and checking if any border point is observed during BFS. if no, then note all points covered during the current BFS and mark them 'X'. if border element found, then complete the BFS, however, keep the points as 'O'