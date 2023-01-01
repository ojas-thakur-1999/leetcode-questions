# Link to solutions
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/869044770/?envType=study-plan&id=data-structure-ii

# insights
* if we observe the in-order and pre-order traversals, we can see a recursion relation
* the first element of pre-order is the root at that level. if we search for this element in the in-order traversal, then the sub-array to the left of this element is the inorder traversal of left child node and same to the right.
* also, if length of above left subarray of inorder traversal is N, then the subarray (start+1, start+N) of pre-order traversal, is the pre-order traversal of the left child node and same to the right.