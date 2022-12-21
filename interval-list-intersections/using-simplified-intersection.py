class Solution:
    def intervalIntersection(self, firstList, secondList):
        i = 0
        j = 0
        result = []
        intersection_start = intersection_end = 0
        while i < len(firstList) and j < len(secondList):
            intersection_start = max(firstList[i][0], secondList[j][0])
            intersection_end = min(firstList[i][1], secondList[j][1])
            if intersection_start <= intersection_end:
                result.append([intersection_start, intersection_end])
            if firstList[i][1] < secondList[j][1]:
                i += 1
            else:
                j += 1
        
        return result