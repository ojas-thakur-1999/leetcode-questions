# Link to solutions
https://leetcode.com/problems/combination-sum-ii/submissions/866854983/?envType=study-plan&id=algorithm-ii

# Insights
first sorting the array and then traversing over it level by level using a loop (as if making a decision tree). in the recursive sub-problems, if we come across duplicates, then select the first duplicate at each level and ignore the rest of the duplicates.