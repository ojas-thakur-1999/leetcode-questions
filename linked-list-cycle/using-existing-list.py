# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        placeHolderNode = ListNode()
        while head != None:
            if head.next is not placeHolderNode:
                temp = head.next
                head.next = placeHolderNode
                head = temp
            else:
                return True
        return False