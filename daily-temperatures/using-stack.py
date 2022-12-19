class Solution:
    def dailyTemperatures(self, temperatures):
        n = len(temperatures)
        results = [0]*n
        stack = [0]
        for i in range(1, n):
            while stack and temperatures[stack[-1]] < temperatures[i]:
                top = stack.pop()
                results[top] = i - top
            stack.append(i)
        
        return results