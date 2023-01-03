#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        return usingRecursion(text1, 0, text2, 0);
    }
private:
    int usingRecursion(string &text1, int start1, string &text2, int start2) {
        if (text1.size() == start1 || text2.size() == start2) {
            return 0;
        } else if (text1[start1] == text2[start2]) {
            return 1+usingRecursion(text1, start1+1, text2, start2+1);
        } else {
            return max(
                usingRecursion(text1, start1, text2, start2+1),
                usingRecursion(text1, start1+1, text2, start2)
            );
        }
    }
};

int main() {
    Solution sol;
    string s1 = "abcde";
    string s2 = "ace";
    printf("%d\n\n", sol.longestCommonSubsequence(s1, s2));
}