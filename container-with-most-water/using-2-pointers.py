class Solution:
    def maxArea(self, heights):
        if not heights:
            return 0
        
        i = 0
        j = len(heights) - 1
        max_area = min(heights[i], heights[j])*(j-i)
        while j-i > 0:
            max_area = max(max_area, min(heights[i], heights[j])*(j-i))
            if heights[i] < heights[j]:
                i += 1
            elif heights[i] > heights[j]:
                j -= 1
            else:
                i += 1
        
        return max_area