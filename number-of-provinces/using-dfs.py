class Solution:
    def findCircleNum(self, isConnected):
        if not isConnected:
            return 0
        
        no_of_provinces = 0
        for i in range(len(isConnected)):
            if isConnected[i][i]:
                self.dfs(isConnected, i, i)
                no_of_provinces += 1

        return no_of_provinces
    
    def dfs(self, isConnected, x, y):
        if x < 0 or x > len(isConnected)-1 or y < 0 or y > len(isConnected)-1 or isConnected[x][y] != 1:
            return
        
        isConnected[x][y] = 0
        isConnected[y][x] = 0

        for j in range(len(isConnected)):
            if isConnected[x][j] == 1:
                self.dfs(isConnected, j, x)