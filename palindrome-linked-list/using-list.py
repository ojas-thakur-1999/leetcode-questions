# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        if not head:
            return head
        
        arr = []
        while head:
            arr.append(head.val)
            head = head.next
        
        lenArr = len(arr)
        for i in range(lenArr//2):
            if arr[i] != arr[len(arr)-1-i]:
                return False

        return True