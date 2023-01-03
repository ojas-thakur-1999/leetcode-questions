# Link to solutions
https://leetcode.com/problems/word-break/submissions/870387365/?envType=study-plan&id=algorithm-ii

# Insights
* tried one solution using a recursive approach, of iterating through the array and removing the dictionary words one by one, then checking recursively for the split parts (this approach failed because of plural words like cat and cats both being present in the dictionary)
* dp approach is to keep moving from the start of the array and check if the word formed so far, matches with any of the dictionary words. if yes, then update the starting point and check from there.