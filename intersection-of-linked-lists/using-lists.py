# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        listAAddresses = []
        listBAddresses = []
        tempHeadA = headA
        tempHeadB = headB
        while tempHeadA:
            listAAddresses.append(id(tempHeadA))
            tempHeadA = tempHeadA.next
        
        while tempHeadB:
            listBAddresses.append(id(tempHeadB))
            tempHeadB = tempHeadB.next

        lenA = len(listAAddresses)
        lenB = len(listBAddresses)
        matchingAddress = None
        for i in range(min(lenA, lenB)):
            if listAAddresses[lenA-1-i] == listBAddresses[lenB-1-i]:
                continue
            else:
                if i != 0:
                    matchingAddress = listAAddresses[lenA-i]
                elif i == 0 and (lenA == 1 or lenB == 1):
                    matchingAddress = listAAddresses[lenA-1-i]
                
                break
        
        if not matchingAddress:
            return None

        listToTraverse = headA if lenA < lenB else headB
        while listToTraverse != None:
            if id(listToTraverse) == matchingAddress:
                return listToTraverse
            else:
                listToTraverse = listToTraverse.next
        
        return None

