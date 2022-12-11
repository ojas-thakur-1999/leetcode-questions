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
        return self.recursiveBFS(q)-1

    def recursiveBFS(self, q) -> int:
        if len(q) == 0:
            return 0

        currLevelWidth = len(q)
        for i in range(currLevelWidth):
            currNode = q.popleft()
            if not currNode:
                continue
            q.append(currNode.left)
            q.append(currNode.right)

        return 1 + self.recursiveBFS(q)