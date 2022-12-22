class Solution:
    def addStrings(self, num1, num2):
        if not num1:
            return num2
        elif not num2:
            return num1

        res = [-1] * (max(len(num1), len(num2)) + 1)
        idx1 = len(num1)-1
        idx2 = len(num2)-1
        idx3 = len(res)-1
        carry = 0
        while idx1 >= 0 and idx2 >= 0:
            o1 = int(num1[idx1])
            o2 = int(num2[idx2])
            sum = o1 + o2 + carry
            res[idx3] = sum % 10
            carry = sum // 10
            idx1 -= 1
            idx2 -= 1
            idx3 -= 1

        if idx1 < 0 and idx2 < 0:
            if carry:
                res[idx3] = carry
            return self.listToString(res)
        elif idx1 < 0:
            while idx2 >= 0:
                o2 = int(num2[idx2])
                sum = o2 + carry
                res[idx3] = sum % 10
                carry = sum // 10
                idx2 -= 1
                idx3 -= 1
            if carry:
                res[idx3] = carry
            return self.listToString(res)
        elif idx2 < 0:
            while idx1 >= 0:
                o1 = int(num1[idx1])
                sum = o1 + carry
                res[idx3] = sum % 10
                carry = sum // 10
                idx1 -= 1
                idx3 -= 1
            if carry:
                res[idx3] = carry
            return self.listToString(res)
    
    def listToString(self, list):
        list_to_string = ""
        for num in list:
            if num < 0:
                pass
            else:
                list_to_string += f"{num}"
        
        return list_to_string