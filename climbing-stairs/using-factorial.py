class Solution:
    def factorial(self, n: int) -> int:
        if n == 0:
            return 1
        return n*self.factorial(n-1)

    def climbStairs(self, n: int) -> int:
        maxTwos = n // 2
        numWays = 0
        for i in range(maxTwos+1):
            currNumTwos = i
            currNumOnes = n - 2*currNumTwos
            tempWays = self.factorial(currNumTwos + currNumOnes) // (self.factorial(currNumTwos) * self.factorial(currNumOnes))
            numWays += tempWays
        return numWays