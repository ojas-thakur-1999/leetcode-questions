from collections import deque
class Solution:
    def solve(self, board):
        if not board:
            return 0
        
        m = len(board)
        n = len(board[0])
        visited = [0]*m
        for i in range(m):
            visited[i] = [0]*n

        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == 'O' and visited[i][j] == 0:
                    self.markRegion(board, visited, i, j)
        
    def markRegion(self, board, visited, x, y):
        m = len(board)
        n = len(board[0])
        visited_in_this_region = []
        found_border = False
        
        q = deque()
        q.append((x, y))
        visited_in_this_region.append((x, y))
        visited[x][y] = 1
        
        while q:
            i, j = q.popleft()
            if i == m-1 or i == 0 or j == 0 or j == n-1:
                found_border = True
            neighbours = [
                (i-1, j),
                (i, j+1),
                (i+1, j),
                (i, j-1)
            ]
            for p_x, p_y in neighbours:
                if (p_x >= 0 and p_x < m) and (p_y >= 0 and p_y < n) and board[p_x][p_y] == 'O' and visited[p_x][p_y] == 0:
                    visited[p_x][p_y] = 1
                    visited_in_this_region.append((p_x, p_y))
                    q.append((p_x, p_y))
        
        if not found_border:
            for x, y in visited_in_this_region:
                board[x][y] = 'X'