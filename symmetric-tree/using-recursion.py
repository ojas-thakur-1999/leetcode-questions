# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        return self.isSimilar(root.left, root.right)
    
    def isSimilar(self, root1, root2) -> bool:
        if not root1:
            return not root2
        if not root2:
            return not root1

        nodeSimilar = root1.val == root2.val
        if not nodeSimilar:
            return False

        leftSimilar = self.isSimilar(root1.left, root2.right)
        if not leftSimilar:
            return False

        rightSimilar = self.isSimilar(root1.right, root2.left)
        if not rightSimilar:
            return False

        return True