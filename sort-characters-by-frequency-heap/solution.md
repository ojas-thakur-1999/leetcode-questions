# Link to solution
https://leetcode.com/problems/sort-characters-by-frequency/submissions/872546910/?envType=study-plan&id=data-structure-ii

# Insights
* one approach is to use a heap, with nodes(char value, int frequency) as its elements and sort them based on frequency.
* another approach is to make an array  of counts and update the index of ascii representation of the character.
* store touples in the array, with first part being the count and second part being asci representation
* now sort based on count and print the string by converting asci representation to char