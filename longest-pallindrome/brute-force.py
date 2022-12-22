class Solution:
    def longestPalindrome(self, s):
        n = len(s)
        found_alphabets = {}
        for c in s:
            if c not in found_alphabets.keys():
                found_alphabets[c] = 1
            else:
                found_alphabets[c] += 1
        
        found_odd_alphabet = False
        no_of_pairs = 0
        for alphabet in found_alphabets.keys():
            if found_alphabets[alphabet] % 2 == 1:
                found_odd_alphabet = True
            
            no_of_pairs += found_alphabets[alphabet] // 2
        
        length = no_of_pairs*2
        if found_odd_alphabet:
            length += 1
        
        return length
