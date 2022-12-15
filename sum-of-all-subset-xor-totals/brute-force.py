class Solution:
    def subsetXORSum(self, nums) -> int:
        XORSum = 0
        subsets = [[]]
        for i in range(len(nums)):
            self.makeSubsets(nums[i], subsets)
        
        for subset in subsets:
            XORSum += self.getXOROfArray(subset)

        return XORSum

    def makeSubsets(self, extraNumber, subsets):
        lenSubsets = len(subsets)
        for i in range(lenSubsets):
            tempArr = subsets[i].copy()
            tempArr.append(extraNumber)
            subsets.append(tempArr)

        return

    def getXOROfArray(self, arr):
        if len(arr) == 0:
            return 0
        
        XORSum = arr[0]
        for i in range(1, len(arr)):
            XORSum = XORSum ^ arr[i]
        
        return XORSum