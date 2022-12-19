class Solution:
    def dailyTemperatures(self, temperatures):
        answers = []
        for i in range(len(temperatures)):
            answer = 0
            for j in range(i+1, len(temperatures)):
                if temperatures[j] > temperatures[i]:
                    answer = j-i
                    break
            answers.append(answer)
        return answers