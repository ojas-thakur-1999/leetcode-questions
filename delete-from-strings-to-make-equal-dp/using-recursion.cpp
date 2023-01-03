#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        return usingRecursion(word1, 0, word2, 0);
    }
private:
    int usingRecursion(string &word1, int idx1, string &word2, int idx2) {
        if (idx1 == word1.size()) {
            return word2.size()-idx2;
        } else if (idx2 == word2.size()) {
            return word1.size()-idx1;
        }

        if (word1[idx1] == word2[idx2]) {
            return usingRecursion(word1, idx1+1, word2, idx2+1);
        } else {
            return min(1+usingRecursion(word1, idx1, word2, idx2+1), 1+usingRecursion(word1, idx1+1, word2, idx2));
        }
    }
};

int main() {
    Solution sol;
    string s1 = "leetcode";
    string s2 = "etxco";
    printf("%d\n\n", sol.minDistance(s1, s2));
}