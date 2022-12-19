class Solution:
    def rotate(self, matrix):
        n = len(matrix)
        for i in range(n//2):
            for j in range(n-1-2*i):
                temp1 = matrix[i][i+j]
                temp2 = matrix[i+j][n-1-i]

                matrix[i+j][n-1-i] = temp1
                temp1 = temp2
                temp2 = matrix[n-1-i][n-1-i-j]

                matrix[n-1-i][n-1-i-j] = temp1
                temp1 = temp2
                temp2 = matrix[n-1-i-j][i]

                matrix[n-1-i-j][i] = temp1
                temp1 = temp2
                temp2 = matrix[i][i+j]

                matrix[i][i+j] = temp1
