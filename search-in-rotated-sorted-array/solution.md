# Link to solutions
https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/862119915/?envType=study-plan&id=algorithm-ii

# Insights
We can use a recursive approach to first find the pivot and then straighten out the array, followed by binary search in the fixed array. However, we can also directly search in the rotated array, by checking the regions start-mid and mid-end for the presence of pivot and taking recursive steps accordingly.