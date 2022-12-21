class Solution:
    def backspaceCompare(self, s, t):
        stack1 = []
        for i in range(len(s)):
            if s[i] == '#':
                if stack1:
                    stack1.pop()
            else:
                stack1.append(s[i])
        
        stack2 = []
        for i in range(len(t)):
            if t[i] == '#':
                if stack2:
                    stack2.pop()
            else:
                stack2.append(t[i])
        
        if len(stack1) != len(stack2):
            return False
        
        for i in range(len(stack1)):
            if stack1[i] != stack2[i]:
                return False
        
        return True