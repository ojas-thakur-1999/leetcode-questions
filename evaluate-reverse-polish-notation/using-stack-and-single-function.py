import math
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            if token == "+":
                token1 = stack.pop()
                token2 = stack.pop()
                res = token2 + token1
                stack.append(res)
            elif token == "-":
                token1 = stack.pop()
                token2 = stack.pop()
                res = token2 - token1
                stack.append(res)
            elif token == "*":
                token1 = stack.pop()
                token2 = stack.pop()
                res = token2 * token1
                stack.append(res)
            elif token == "/":
                token1 = stack.pop()
                token2 = stack.pop()
                res = token2 / token1
                res = math.floor(res) if res > 0 else math.ceil(res)
                stack.append(res)
            else:
                stack.append(int(token))
            
        return stack.pop()