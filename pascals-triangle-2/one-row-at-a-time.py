class Solution:
    def getRow(self, n):
        if n == 0:
            return [1]
        
        prev = [1]
        for i in range(1, n+1):
            curr_no = [0]*(i+1)
            prev_len = i
            for j in range(len(curr_no)):
                if j-1 >= 0:
                    curr_no[j] += prev[j-1]
                if j <= prev_len - 1:
                    curr_no[j] += prev[j]
            prev = curr_no
        
        return prev
