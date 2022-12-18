# Link to solutions
https://leetcode.com/problems/sort-colors/submissions/861687483/?envType=study-plan&id=data-structure-ii

# Insights
using the Dutch national flag algo, where we keep one counter to iterate over the array, one pointer to point to the lower end and one pointer to point to the higher end of the array. if the iterative pointer is 0, then swap it with lower pointer and increment both pointers. if iterative pointer is 1, only increase it. if iterative pointer is 2, then swap it with higher pointer and decrement the higher point.