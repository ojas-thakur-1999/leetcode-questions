# Link to solutions
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/submissions/869090283/?envType=study-plan&id=data-structure-ii

# Insights
* one method is to use a doubly linked list, and push/pop element from the back as well as front.
* another approach is, instead of popping from the back and pushing at the front for reverse direction, we can just do the regular push pop, only iterate the elements of the array in a reverse order.