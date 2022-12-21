class Solution:
    def backspaceCompare(self, str1, str2):
        i = len(str1)-1
        j = len(str2)-1
        backspaces_1 = 0
        backspaces_2 = 0
        while i >= 0 and j >= 0:
            if str1[i] == '#':
                backspaces_1 += 1
                i -= 1
            elif str2[j] == '#':
                backspaces_2 += 1
                j -= 1
            else:
                if backspaces_1 == 0 and backspaces_2 == 0:
                    if str1[i] != str2[j]:
                        return False
                    else:
                        i -= 1
                        j -= 1
                elif backspaces_1 != 0:
                    i -= 1
                    backspaces_1 -= 1
                elif backspaces_2 != 0:
                    j -= 1
                    backspaces_2 -= 1

        if i < 0 and j < 0:
            return True
        elif i < 0:
            diff_found = False
            while j >= 0:
                if str2[j] == '#':
                    backspaces_2 += 1
                    j -= 1
                else:
                    if backspaces_2 == 0:
                        diff_found = True
                        break
                    else:
                        j -= 1
                        backspaces_2 -= 1
            if diff_found:
                return False
            else:
                return True
        else:
            diff_found = False
            while i >= 0:
                if str1[i] == '#':
                    backspaces_1 += 1
                    i -= 1
                else:
                    if backspaces_1 == 0:
                        diff_found = True
                        break
                    else:
                        i -= 1
                        backspaces_1 -= 1
            if diff_found:
                return False
            else:
                return True