class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n1 = len(text1)+1
        n2 = len(text2)+1
        dp = [0]*(n1)
        for i in range(n1):
            dp[i] = [0]*(n2)
        
        for i in reversed(range(n1)):
            for j in reversed(range(n2)):
                if (i == n1-1) or (j == n2-1):
                    dp[i][j] = 0
                elif text1[i] == text2[j]:
                    dp[i][j] = 1 + dp[i+1][j+1]
                else:
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1])
        
        return dp[0][0]