# Link to solutions
https://leetcode.com/problems/path-sum-ii/submissions/869115391/?envType=study-plan&id=data-structure-ii

# Insights
* one approach is to use recursion, starting from root to leaf nodes, and calculating the sum for all such paths.
* in this approach, we keep a track of the current path using a vector. This vector can be passed by value as well as by reference. 
* pass by reference is significantly faster than pass by value because we don't have to copy the whole data in a function call stack
* vector.push_back() -> copies data from one place to the current vector memory position