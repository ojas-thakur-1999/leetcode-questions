# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        foundCycle = False
        currNodePtr = head
        foundNodeAddresses = {}
        while currNodePtr != None:
            if id(currNodePtr) not in foundNodeAddresses.keys():
                foundNodeAddresses[id(currNodePtr)] = True
            else:
                foundCycle = True
                break
            
            currNodePtr = currNodePtr.next
        
        return foundCycle
