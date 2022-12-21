class Solution:
    def maxArea(self, heights):
        if not heights:
            return 0
        i = 0
        j = len(heights)-1
        max_area = 0
        while i < j:
            min_height = min(heights[i], heights[j])
            max_area = max(max_area, min_height*(j-i))
            if heights[i] <= min_height:
                i += 1
                while i <= len(heights)-1 and heights[i] <= min_height:
                    i += 1
            elif heights[j] <= min_height:
                j -= 1
                while j >= 0 and heights[j] <= min_height:
                    j -= 1
        
        return max_area