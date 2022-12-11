# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        q = deque()
        q.append(root)
        depth = -1
        while q:
            depth += 1
            nodesAtLevel = len(q)
            for i in range(nodesAtLevel):
                node = q.popleft()
                if node:
                    q.append(node.left)
                    q.append(node.right)
        return depth