import math
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        operands = {
            "+": self.add, 
            "-": self.sub, 
            "*": self.mul, 
            "/": self.div
        }
        stack = []
        for token in tokens:
            if token in operands.keys():
                token1 = stack.pop()
                token2 = stack.pop()
                res = operands[token](token2, token1)
                stack.append(res)
            else:
                stack.append(int(token))
        
        return stack.pop()
    
    def add(self, int1, int2):
        return int1 + int2
    
    def sub(self, int1, int2):
        return int1 - int2
    
    def mul(self, int1, int2):
        return int1 * int2
    
    def div(self, int1, int2):
        res = int1 / int2
        return math.floor(res) if res > 0 else math.ceil(res)