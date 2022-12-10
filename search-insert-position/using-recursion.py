class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        return self.searchInsertBinary(0, target, nums)
    
    def searchInsertBinary(self, startIdx: int, target: int, arr: List[int]) -> int:
        if arr == None:
            return -1

        arrLen = len(arr)

        if arrLen == 1:
            if target == arr[0]:
                return startIdx
            elif target < arr[0]:
                return startIdx
            else:
                return startIdx + 1

        middleIdx = floor(arrLen/2)
        if target == arr[middleIdx]:
            return startIdx + middleIdx
        elif target < arr[middleIdx]:
            return self.searchInsertBinary(startIdx, target, arr[:middleIdx])
        else:
            if middleIdx + 1 < arrLen:
                return self.searchInsertBinary(startIdx + middleIdx + 1, target, arr[middleIdx + 1:])
            else:
                return startIdx + middleIdx + 1
                