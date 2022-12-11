class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ret = [[] for _ in range(numRows)]
        for numRow, row in enumerate(ret):
            currentRow = numRow+1
            while len(row) < currentRow:
                if len(row) == 0 or len(row) == currentRow-1:
                    row.append(1)
                else:
                    row.append(ret[currentRow-2][len(row)-1] + ret[currentRow-2][len(row)])
        return ret