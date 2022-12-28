#include<vector>
#include<string>
#include<sstream>
using namespace std;

class Solution {
    public:
    vector<string> letterCombinations(string digits) {
        vector<string> results;
        if (digits == "") {
            return results;
        }
        string mappings[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string string_so_far;
        recursion(digits, mappings, results, string_so_far, 0);
        return results;
    }

    void recursion(string &digits, string *mappings, vector<string> &results, string string_so_far, int idx) {
        if (idx == digits.size()) {
            results.push_back(string_so_far);
            return;
        }
        stringstream obj;
        int digit;
        obj << digits[idx];
        obj >> digit;
        string digit_mapping = mappings[digit];
        for (int i=0; i<digit_mapping.size(); i++) {
            string_so_far += digit_mapping[i];
            recursion(digits, mappings, results, string_so_far, idx+1);
            string_so_far.pop_back();
        }
    }

};