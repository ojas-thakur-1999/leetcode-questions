#include<vector>
#include<string>
#include<iostream>

using namespace std;

void print2DVector(vector<vector<int>> &vec) {
    for (int i=0; i<vec.size(); i++) {
        printf("[");
        for (int j=0; j<vec[i].size(); j++) {
            printf("%d, ", vec[i][j]);
        }
        printf("]\n");
    }
}

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0 || wordDict.size() == 0) {
            return false;
        }
        bool dp[s.size()+1];
        for (int i=0; i<s.size()+1; i++) {
            dp[i] = false;
        }
        dp[0] = true;
        for (int i=1; i<=s.size(); i++) {
            for (int j=i-1; j>=0; j--) {
                if (dp[j]) {
                    string to_check;
                    for (int k=j; k<i; k++) {
                        to_check += s[k];
                    }
                    bool found=false;
                    for (int k=0; k<wordDict.size(); k++) {
                        if (to_check == wordDict[k]) {
                            found = true;
                            break;
                        }
                    }
                    if (found) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};

int main() {
    Solution sol;
    string s = "leetcode";
    vector<string> word_dict = {"leet", "code"};
    // string s = "catsandog";
    // vector<string> word_dict = {"cats","dog","sand","and","cat"};
    // string s = "applepenapple";
    // vector<string> word_dict = {"apple", "pen"};
    // string s = "catskicatcats";
    // vector<string> word_dict = {"cats","cat","dog","ski", "ki"};

    if (sol.wordBreak(s, word_dict)) {
        printf("possible\n\n");
    } else {
        printf("not possible\n\n");
    }
}