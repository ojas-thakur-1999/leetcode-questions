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

        return self.isEqual(root, subRoot) or self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)
    
    def isEqual(self, root, subRoot):
        
        if not root and not subRoot:
            return True
        elif not root or not subRoot:
            return False
        
        if root.val != subRoot.val:
            return False
        
        return self.isEqual(root.left, subRoot.left) and self.isEqual(root.right, subRoot.right)
        
