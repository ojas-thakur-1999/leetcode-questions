# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None
        
        stack = []
        while head:
            stack.append(head)
            head = head.next
        
        newHead = stack.pop()
        tempHead = newHead
        while stack:
            newNext = stack.pop()
            tempHead.next = newNext
            tempHead = newNext
        tempHead.next = None

        return newHead
