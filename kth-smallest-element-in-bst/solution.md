# Link to solutions
https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/871177536/?envType=study-plan&id=data-structure-ii

# Insights
* the kth smallest element will be the kth element in it's in order traversal
* since we don't want the in-order traversal, only the kth element, we can remove the vector and instead keep an count, which will first update when we reach the left most number in the subtree, then for the head then then for the right subtree and so on. Doing this, we will be able to find the k-th smallest number when count reaches k.