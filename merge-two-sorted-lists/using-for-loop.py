# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        list1CurrIdx = list1
        list2CurrIdx = list2
        if list1CurrIdx == None:
            return list2CurrIdx
        elif list2CurrIdx == None:
            return list1CurrIdx

        resultHead = ListNode
        resultCurrIdx = resultHead
        if list1CurrIdx.val < list2CurrIdx.val:
            resultCurrIdx.val = list1CurrIdx.val
            list1CurrIdx = list1CurrIdx.next
        else:
            resultCurrIdx.val = list2CurrIdx.val
            list2CurrIdx = list2CurrIdx.next

        while True:
            if list1CurrIdx == None:
                resultCurrIdx.next = list2CurrIdx
                break
            elif list2CurrIdx == None:
                resultCurrIdx.next = list1CurrIdx
                break
            else:
                if list1CurrIdx.val < list2CurrIdx.val:
                    nextList1Idx = list1CurrIdx.next
                    nextList2Idx = list2CurrIdx
                    resultCurrIdx.next = list1CurrIdx

                    resultCurrIdx = resultCurrIdx.next
                    list1CurrIdx = nextList1Idx
                    list2CurrIdx = nextList2Idx
                else:
                    nextList1Idx = list1CurrIdx
                    nextList2Idx = list2CurrIdx.next
                    resultCurrIdx.next = list2CurrIdx

                    resultCurrIdx = resultCurrIdx.next
                    list1CurrIdx = nextList1Idx
                    list2CurrIdx = nextList2Idx
        return resultHead
