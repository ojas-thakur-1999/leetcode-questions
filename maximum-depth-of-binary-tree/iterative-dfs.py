# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        stack = [(root, 0)]
        maxDepth = 0
        while stack:
            leftMostNode, currentDepth = stack.pop()
            if leftMostNode:
                stack.append((leftMostNode.right, currentDepth+1))
                stack.append((leftMostNode.left, currentDepth+1))
                maxDepth = max(maxDepth, currentDepth+1)
        return maxDepth