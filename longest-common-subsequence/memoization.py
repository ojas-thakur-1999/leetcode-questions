class Solution:
    def __init__(self):
        self.text1 = ""
        self.text2 = ""
        self.lenText1 = 0
        self.lenText2 = 0

    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        self.text1 = text1
        self.lenText1 = len(text1)
        self.text2 = text2
        self.lenText2 = len(text2)
        memoArray = [-1]*(self.lenText1+1)
        for i in range(self.lenText1+1):
            memoArray[i] = [-1]*(self.lenText2+1)

        return self.subproblem(0, 0, memoArray)

    def subproblem(self, idx1, idx2, memoArray):
        if memoArray[idx1][idx2] < 0:
            if self.lenText1 == idx1 or self.lenText2 == idx2:
                memoArray[idx1][idx2] = 0
            elif self.text1[idx1] == self.text2[idx2]:
                memoArray[idx1][idx2] = 1 + self.subproblem(idx1+1, idx2+1, memoArray)
            else:
                memoArray[idx1][idx2] = max(self.subproblem(idx1, idx2+1, memoArray), self.subproblem(idx1+1, idx2, memoArray))        

        return memoArray[idx1][idx2]
