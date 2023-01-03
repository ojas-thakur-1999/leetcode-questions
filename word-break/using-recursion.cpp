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
    // this can be solved using recursion such that in each step, we take a word from the dict
    // then check all occurences of it. then we split the string accordingly and remove this word from the dict
    // now we call this function on all the split parts with new dict value
    // if any call returns true, break and return true
    // else, add back the deleted word, and repeat the same above steps with another word from the dict.
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0 || wordDict.size() == 0) {
            return false;
        }
        return usingRecursion(s, wordDict, 0, s.size()-1);
    }
private:
    bool usingRecursion(string &s, vector<string> &word_dict, int start_idx, int end_idx) {
        if (end_idx < start_idx) {
            return false;
        }

        for (int i=0; i<word_dict.size(); i++) {
            string word_to_check = word_dict[i];
            int part_start = start_idx;
            int word_idx = 0;
            vector<vector<int>> parts;
            for (int j=start_idx; j<=end_idx; j++) {
                if (s[j] == word_to_check[word_idx]) {
                    if (word_idx == word_to_check.size()-1) {
                        vector<int> current_part = {part_start, j-int(word_to_check.size())};
                        parts.push_back(current_part);
                        word_idx = 0;
                        part_start = j+1;
                    } else {
                        word_idx++;
                    }
                } else {
                    word_idx = 0;
                    if (s[j] == word_to_check[word_idx]) {
                        word_idx++;
                    }
                }
            }
            vector<int> v={part_start, end_idx};
            parts.push_back(v);
            print2DVector(parts);
            if (parts.size() == 1 && parts[0][0] == start_idx && parts[0][1] == start_idx-1) {
                return true;
            } else if (parts.size() == 1) {
                continue;
            }
            vector<string> new_word_dict;
            for (int k=0; k<i; k++) {
                new_word_dict.push_back(word_dict[k]);
            }
            for (int k=i+1; k<word_dict.size(); k++) {
                new_word_dict.push_back(word_dict[k]);
            }
            bool isPossible = true;
            for (int k=0; k<parts.size(); k++) {
                if (parts[k][0] <= parts[k][1]) {
                    isPossible = isPossible && usingRecursion(s, new_word_dict, parts[k][0], parts[k][1]);
                }
            }
            if (isPossible) {
                return true;
            }
            new_word_dict.clear();
        }

        return false;
    }
};

int main() {
    Solution sol;
    // string s = "leetcode";
    // vector<string> word_dict = {"leet", "code"};
    // string s = "catsandog";
    // vector<string> word_dict = {"cats","dog","sand","and","cat"};
    // string s = "applepenapple";
    // vector<string> word_dict = {"apple", "pen"};
    string s = "catskicatcats";
    vector<string> word_dict = {"cats","cat","dog","ski"};

    if (sol.wordBreak(s, word_dict)) {
        printf("possible\n\n");
    } else {
        printf("not possible\n\n");
    }
}