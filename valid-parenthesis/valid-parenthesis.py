class Solution:
    def isValid(self, str):
        stack = []
        mappings = {
            '{':'}',
            '(':')',
            '[':']'
        }
        for i in range(len(str)):
            if str[i] in mappings.keys():
                stack.append(str[i])
            else:
                if len(stack) == 0:
                    return False
                topElement = stack.pop()
                if str[i] != mappings[topElement]:
                    return False
        if len(stack) != 0:
            return False
        return True