class Solution:
    def generateMatrix(self, n):
        matrix = [0]*n
        for i in range(n):
            matrix[i] = [0]*n
        
        current_number = 1
        for i in range(n//2):
            diff = n-1-2*i
            for j in range(0, diff):
                matrix[i][i+j] = current_number
                matrix[i+j][n-1-i] = current_number + diff
                matrix[n-1-i][n-1-i-j] = current_number + 2*diff
                matrix[n-1-i-j][i] = current_number + 3*diff
                current_number += 1
            current_number = matrix[i+1][i]+1

        if n%2 == 1:
            matrix[n//2][n//2] = current_number
        
        return matrix
