class Solution:
    def searchMatrix(self, matrix, target):
        if len(matrix) == 0:
            return -1
        return self.searchRecursive(target, matrix, 0, len(matrix), 0, len(matrix[0]))

    def searchRecursive(self, target, matrix, x_start, x_end, y_start, y_end):
        if x_end <= x_start or y_end <= y_start:
            return False
        
        # search in horizontal array
        found_y = -1
        for i in range(y_end-y_start):
            if matrix[x_start][y_start+i] == target:
                return True
            elif matrix[x_start][y_start+i] < target:
                found_y = i
            else:
                break

        if found_y == -1:
            return False
        
        # search in vertical array
        found_x = -1
        for i in range(x_end-x_start):
            if matrix[x_start+i][y_start] == target:
                return True
            elif matrix[x_start+i][y_start] < target:
                found_x = i
            else:
                break
        
        if found_x == -1:
            return False
        
        return self.searchRecursive(target, matrix, x_start+1, x_start+found_x+1, y_start+1, y_start+found_y+1)