class Solution:
    def merge(self, intervals):
        number_line = [0]*(2*10000 + 4)
        for interval in intervals:
            start, end = interval
            for i in range(2*start, 2*end + 1):
                number_line[i] = 1

        result = []
        prev_state = 0
        block_start = 0
        for i in range(len(number_line)):
            if number_line[i] == 1:
                if prev_state == 0:
                    block_start = i
                    prev_state = 1
            else:
                if prev_state == 1:
                    result.append([block_start // 2, (i-1) // 2])
                    prev_state = 0

        return result