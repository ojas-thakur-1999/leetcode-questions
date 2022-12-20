class Solution:
    def searchMatrix(self, matrix, target):
        M, N = len(matrix), len(matrix[0])

        if target < matrix[0][0] or target > matrix[M-1][N-1]:
            return False
        
        row, column = M-1, 0

        while row >= 0 and column < N:
            if matrix[row][column] == target:
                return True
            elif matrix[row][column] > target:
                row -= 1
            else:
                column += 1
        
        return False