class Solution:
    def eraseOverlapIntervals(self, intervals):
        intervals.sort(key=lambda x : x[0])
        
        removed_count = 0
        prev = intervals[0]
        for i in range(1, len(intervals)):
            curr = intervals[i]
            if prev[1] <= curr[0]:
                prev = curr
            elif prev[1] > curr[0]:
                if prev[1] < curr[1]:
                    removed_count += 1
                else:
                    removed_count += 1
                    prev = curr
        
        return removed_count