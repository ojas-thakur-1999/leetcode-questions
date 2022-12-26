
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left = None, right = None, next = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next


class Solution:
    def connect(self, root):
        # represents the current node being visited
        node = root

        # new node which stores the pointer to starting node of next level
        level_head = Node(0)

        # outer loop to cover all levels
        while node:
            # start with pointer pointing to the extra node
            # then in first step, point it to the first node of next level
            # then the successive next elements and so on
            pointer = level_head

            # inner loop to cover all nodes in current level
            while node:
                if node.left:
                    pointer.next = node.left
                    pointer = pointer.next
                
                if node.right:
                    pointer.next = node.right
                    pointer = pointer.next

                # point to the next node of this level
                node = node.next
            
            # move to the next level
            node = level_head.next
            
            level_head.next = None
        
        return root
