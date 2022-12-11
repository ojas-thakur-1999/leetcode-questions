# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        if len(nums) == 1:
            return TreeNode(nums[0], None, None)

        midElement = len(nums) // 2
        currentNode = TreeNode(nums[midElement])
        if midElement > 0:
            currentNode.left = self.sortedArrayToBST(nums[:midElement])
        else:
            currentNode.left = None
            
        if midElement+1 < len(nums):
            currentNode.right = self.sortedArrayToBST(nums[midElement+1:])
        else:
            currentNode.right = None
        return currentNode