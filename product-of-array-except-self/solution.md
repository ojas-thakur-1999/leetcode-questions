# Link to solutions
https://leetcode.com/problems/product-of-array-except-self/submissions/863361748/?envType=study-plan&id=data-structure-ii

# Insights
breaking the problem in two parts, prefix and suffix. for any given index, we can calculate an array of prefix prduct / suffix product in o(n) time by iterating once over the array. both these are then combined to get the complete multiplication.