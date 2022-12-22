class Solution():
    def findAnagrams(self, s1, s2):
        found_indices = []
        previous_anagram = False
        for i in range(len(s1)-len(s2)+1):
            if previous_anagram and s1[i+len(s2)-1] == s1[i-1]:
                found_indices.append(i)
                continue
            if self.isAnagram(s1[i:i+len(s2)], s2):
                found_indices.append(i)
                previous_anagram = True
            else:
                previous_anagram = False
        
        return found_indices

    def isAnagram(self, s1, s2):
        if len(s1) != len(s2):
            return False

        found_alphabets1 = {}
        for c in s1:
            if c not in found_alphabets1.keys():
                found_alphabets1[c] = 1
            else:
                found_alphabets1[c] += 1
        
        found_alphabets2 = {}
        for c in s2:
            if c not in found_alphabets2.keys():
                found_alphabets2[c] = 1
            else:
                found_alphabets2[c] += 1

        found_alphabets1_keys = found_alphabets1.keys()
        found_alphabets2_keys = found_alphabets2.keys()
        if len(found_alphabets1_keys) != len(found_alphabets2_keys):
            return False
        
        for alphabet in found_alphabets1_keys:
            if alphabet not in found_alphabets2_keys:
                return False
            
            if found_alphabets1[alphabet] != found_alphabets2[alphabet]:
                return False
        
        return True