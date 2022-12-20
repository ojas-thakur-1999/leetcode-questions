class Solution:
    def searchMatrix(self, matrix, target):
        if len(matrix) == 0:
            return False
        
        def searchBinary(matrix, target, start, end):
            if start > end:
                return False
            
            columns = len(matrix[0])

            mid = (start + end) // 2
            mid_x = mid // columns
            mid_y = mid % columns

            if matrix[mid_x][mid_y] == target:
                return True
            elif matrix[mid_x][mid_y] > target:
                return searchBinary(matrix, target, start, mid-1)
            else: 
                return searchBinary(matrix, target, mid+1, end)
        
        rows = len(matrix)
        columns = len(matrix[0])
        return searchBinary(matrix, target, 0, rows*columns-1)
