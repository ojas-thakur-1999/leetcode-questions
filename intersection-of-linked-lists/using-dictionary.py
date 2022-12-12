# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        visitedAddresses = {}
        while headA or headB:
            if headA:
                addressA = id(headA)
                if addressA not in visitedAddresses.keys():
                    visitedAddresses[addressA] = True
                    headA = headA.next
                else:
                    return headA
            if headB:
                addressB = id(headB)
                if addressB not in visitedAddresses.keys():
                    visitedAddresses[addressB] = True
                    headB = headB.next
                else:
                    return headB
        
        return None
