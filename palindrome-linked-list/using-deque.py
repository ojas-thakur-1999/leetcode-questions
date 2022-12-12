# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        if not head:
            return head
        
        q = deque()
        while head:
            q.append(head.val)
            head = head.next
        
        for i in range(len(q)//2):
            if q.popleft() != q.pop():
                return False

        return True