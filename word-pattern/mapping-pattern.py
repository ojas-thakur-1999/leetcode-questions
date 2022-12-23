class Solution:
    def wordPattern(self, pattern, s):
        mapping = [-1]*len(pattern)
        for i in range(len(pattern)):
            for j in range(i-1, -1, -1):
                if pattern[j] == pattern[i]:
                    mapping[i] = j
                    break
        
        idx = 0
        words = [""]*len(s)
        curr_word = ""
        for i in range(len(s)+1):
            if i == len(s) or s[i] == ' ':
                words[idx] = curr_word
                if idx == len(pattern):
                    return False
                if mapping[idx] >= 0:
                    prev_word = words[mapping[idx]]
                    if prev_word != curr_word:
                        return False
                else:
                    for j in range(idx):
                        if mapping[j] < 0 and words[j] == words[idx]:
                            return False
                idx += 1
                curr_word = ""
            else:
                curr_word += s[i]
        
        if idx != len(pattern):
            return False

        return True