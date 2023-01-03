#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[word1.size()+1][word2.size()+1];
        for (int j=0; j<word2.size(); j++) {
            dp[word1.size()][word2.size()-1-j] = j+1;
        }
        for (int i=0; i<word1.size(); i++) {
            dp[word1.size()-1-i][word2.size()] = i+1;
        }
        dp[word1.size()][word2.size()] = 0;
        for (int i=word1.size()-1; i>=0; i--) {
            for (int j=word2.size()-1; j>=0; j--) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    dp[i][j] = min(1+dp[i+1][j], 1+dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};

int main() {
    Solution sol;
    string s1 = "leetcode";
    string s2 = "etxco";
    printf("%d\n\n", sol.minDistance(s1, s2));
    // for (int i=0; i<word1.size()+1; i++) {
    //     printf("[");
    //     for (int j=0; j<word2.size()+1; j++) {
    //         printf("%d, ", dp[i][j]);
    //     }
    //     printf("]\n");
    // }
}