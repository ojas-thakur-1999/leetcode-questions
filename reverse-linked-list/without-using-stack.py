# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        
        currPtr = head.next
        nextPtr = currPtr.next
        currPtr.next = head
        head.next = None
        while nextPtr:
            newNextPtr = nextPtr.next
            nextPtr.next = currPtr
            currPtr = nextPtr
            nextPtr = newNextPtr
        
        return currPtr