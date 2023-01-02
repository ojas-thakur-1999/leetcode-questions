# Link to solutions
https://leetcode.com/problems/decode-ways/submissions/869650172/?envType=study-plan&id=algorithm-ii

# Insights
* the recursive relation here was while moving from left to tight, if we know the number of ways in the already covered portion, then we can simply add the number of ways as we consider the current character and the current character + just previous one.