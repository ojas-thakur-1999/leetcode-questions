class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSubtree(self, root, subRoot) -> bool:

        if not root and not subRoot:
            return True
        elif not root or not subRoot:
            return False

        if root.val == subRoot.val:
            return self.isSubtree(root.left, subRoot.left) and self.isSubtree(root.right, subRoot.right)
        else:
            return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)


# subRoot = TreeNode(
#     4,
#     TreeNode(
#         1,
#         None,
#         None
#     ),
#     TreeNode(
#         2,
#         None,
#         None
#     )
# )

# root = TreeNode(
#     3,
#     subRoot,
#     TreeNode(
#         5,
#         None,
#         None
#     )
# )

# print(Solution().isSubtree(root, subRoot))

subRoot = TreeNode(
        1,
        None,
        None
)

root = TreeNode(
    1,
    subRoot,
    None
)

print(Solution().isSubtree(root, subRoot))