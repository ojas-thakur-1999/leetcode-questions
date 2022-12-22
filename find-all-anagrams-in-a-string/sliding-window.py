class Solution:
    def findAnagrams(self, s1, s2):
        if len(s1) < len(s2):
            return []
        
        current_window_alphabets = {}
        s2_alphabets = {}
        for i in range(len(s2)):
            if s1[i] not in current_window_alphabets.keys():
                current_window_alphabets[s1[i]] = 1
            else:
                current_window_alphabets[s1[i]] += 1
            
            if s2[i] not in s2_alphabets.keys():
                s2_alphabets[s2[i]] = 1
            else:
                s2_alphabets[s2[i]] += 1
        
        found_indices = []
        prev_anagram = self.isAnagram(current_window_alphabets, s2_alphabets)
        if prev_anagram:
            found_indices.append(0)

        for i in range(len(s2), len(s1)):
            removed_alphabet = s1[i-len(s2)]
            added_alphabet = s1[i]
            if added_alphabet == removed_alphabet:
                if prev_anagram:
                    found_indices.append(i-len(s2)+1)
            else:
                if added_alphabet in current_window_alphabets.keys():
                    current_window_alphabets[added_alphabet] += 1
                else:
                    current_window_alphabets[added_alphabet] = 1
                
                current_window_alphabets[removed_alphabet] -= 1
                if current_window_alphabets[removed_alphabet] == 0:
                    current_window_alphabets.pop(removed_alphabet)

                if self.isAnagram(current_window_alphabets, s2_alphabets):
                    found_indices.append(i-len(s2)+1)
                    prev_anagram = True
                else:
                    prev_anagram = False
        
        return found_indices

    def isAnagram(self, s1_alphabets, s2_alphabets):
        s1_alphabets_keys = s1_alphabets.keys()
        s2_alphabets_keys = s2_alphabets.keys()
        if len(s1_alphabets_keys) != len(s2_alphabets_keys):
            return False
        
        for alphabet in s1_alphabets_keys:
            if alphabet not in s2_alphabets_keys:
                return False
            
            if s1_alphabets[alphabet] != s2_alphabets[alphabet]:
                return False
        
        return True