class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 0:
            return []
        
        finalResult = [[1]]
        buffer = [1]
        for i in range(2, numRows+1):
            row = []
            for j in range(i):
                pascalNumber = 0
                if j-1 >= 0:
                    pascalNumber += buffer[j-1]
                
                if j < i-1:
                    pascalNumber += buffer[j]
                
                row.append(pascalNumber)
            
            finalResult.append(row)
            buffer = row
        
        return finalResult

