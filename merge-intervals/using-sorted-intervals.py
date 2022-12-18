class Solution:
    def merge(self, intervals):
        if len(intervals) == 0:
            return []

        intervals.sort(key = lambda x: x[0])

        result = []

        p1 = 0
        p2 = 1
        current_interval_start, current_interval_end = intervals[p1]
        while p2 < len(intervals):
            if intervals[p2][0] > current_interval_end:
                result.append([current_interval_start, current_interval_end])
                current_interval_start, current_interval_end = intervals[p2]
                p1 = p2
                p2 += 1
            else:
                current_interval_end = max(current_interval_end, intervals[p2][1])
                p2 += 1
        
        if p1 < len(intervals):
            result.append([current_interval_start, current_interval_end])

        return result