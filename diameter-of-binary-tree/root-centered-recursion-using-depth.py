# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0
        
        currLength = 2 + self.depth(root.left) + self.depth(root.right)
        return max(currLength, self.diameterOfBinaryTree(root.left), self.diameterOfBinaryTree(root.right))
    
    def depth(self, root):
        if not root:
            return -1
        
        return 1 + max(self.depth(root.left), self.depth(root.right))