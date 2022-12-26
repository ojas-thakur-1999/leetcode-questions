from collections import deque
class Solution:
    def shortestPathBinaryMatrix(self, grid):
        if not grid:
            return -1
        
        n = len(grid)
        if grid[0][0] or grid[n-1][n-1]:
            return -1
        
        q = deque()
        q.append((0,0,1))
        while q:
            i, j, len_so_far = q.popleft()
            
            if i==n-1 and j==n-1:
                return len_so_far
            
            surrounding_points = [
                (i-1, j),
                (i-1, j+1),
                (i, j+1),
                (i+1, j+1),
                (i+1, j),
                (i+1, j-1),
                (i, j-1),
                (i-1, j-1)
            ]
            for x, y in surrounding_points:
                if (x >= 0 and x < n) and (y >=0 and y < n) and (grid[x][y] == 0):
                    grid[x][y] = 1
                    q.append((x, y, len_so_far+1))
            
        return -1