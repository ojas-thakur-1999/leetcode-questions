class Solution:
    def eraseOverlapIntervals(self, intervals):
        e = float('-inf')
        removed = 0
        for start, end in sorted(intervals, key=lambda x: x[1]):
            if start >= e:
                e = end
            else:
                removed += 1
        
        return removed