from collections import deque
class Solution:
    def numIslands(self, grid):
        if not grid:
            return 0
        
        count = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    self.bfs(grid, i, j)
                    count += 1
        
        return count

    def bfs(seld, grid, x, y):
        q = deque()
        q.append([x, y])
        while q:
            point_x, point_y = q.popleft()
            if grid[point_x][point_y] != '1':
                continue

            grid[point_x][point_y] = '#'
            
            if point_x > 0 and grid[point_x-1][point_y] == '1':
                q.append([point_x-1, point_y])
            
            if point_x < len(grid) - 1 and grid[point_x+1][point_y] == '1':
                q.append([point_x+1, point_y])
            
            if point_y > 0 and grid[point_x][point_y-1] == '1':
                q.append([point_x, point_y-1])
            
            if point_y < len(grid[0]) - 1 and grid[point_x][point_y+1] == '1':
                q.append([point_x, point_y+1])
        
        return