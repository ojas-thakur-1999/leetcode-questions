class Solution:
    def intervalIntersection(self, firstList, secondList):
        i = j = 0
        result = []
        while i < len(firstList) and j < len(secondList):
            if firstList[i][1] < secondList[j][0]:
                i += 1
            elif firstList[i][1] >= secondList[j][0] and firstList[i][1] <= secondList[j][1]:
                if firstList[i][0] < secondList[j][0]:
                    result.append([secondList[j][0], firstList[i][1]])
                    i += 1
                else:
                    result.append(firstList[i])
                    i += 1
            elif firstList[i][0] < secondList[j][0]:
                result.append(secondList[j])
                j += 1
            elif firstList[i][0] >= secondList[j][0] and firstList[i][0] <= secondList[j][1]:
                result.append([firstList[i][0], secondList[j][1]])
                j += 1
            else:
                j += 1
        
        return result