# Link to solutions
https://leetcode.com/problems/find-the-winner-of-the-circular-game/submissions/868999636/?envType=study-plan&id=data-structure-ii

# Insights
* one solutions is the brute force one, where we loop through the array and mark the eliminated elements after each.
* another method is to use a vector (of initial length N), which stores all the non-eliminated indices. then iterate over all elements of this vector and keep removing the elements one by one.