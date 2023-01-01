#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> left_paranthesis_idx;
        string result;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(') {
                left_paranthesis_idx.push_back(result.size());
                result += s[i];
            } else if (s[i] == ')') {
                if (left_paranthesis_idx.size() > 0) {
                    result += s[i];
                    left_paranthesis_idx.pop_back();
                }
            } else {
                result += s[i];
            }
        }
        if (left_paranthesis_idx.size() == 0) {
            return result;
        }
        
        string final_result;
        int start_idx = 0;
        int end_idx = left_paranthesis_idx[0];
        for (int i=start_idx; i<end_idx; i++) {
            final_result += result[i];
        }
        int size = left_paranthesis_idx.size();

        for (int j=0; j<left_paranthesis_idx.size()-1; j++) {
            start_idx = left_paranthesis_idx[j]+1;
            end_idx = left_paranthesis_idx[j+1];
            for (int i=start_idx; i<end_idx; i++) {
                final_result += result[i];
            }
        }

        start_idx = left_paranthesis_idx[left_paranthesis_idx.size()-1]+1;
        end_idx = result.size();
        for (int i=start_idx; i<end_idx; i++) {
            final_result += result[i];
        }

        return final_result;
    }
};

int main() {
    Solution sol;
    // string input = "))((";
    string input = "(a(b(c)d)";
    printf("input -> %s\n", input.c_str());
    printf("output -> %s\n", sol.minRemoveToMakeValid(input).c_str());
    // printf("check - 2 => i = %d, s[i] = %c, result = %s\n\n", i, s[i], result.c_str());
}