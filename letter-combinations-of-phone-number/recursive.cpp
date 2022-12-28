#include<vector>
#include<string>
#include<sstream>
using namespace std;

class Solution {
    public:
    vector<string> letterCombinations(string digits) {
        vector<string> results;
        string string_so_far;
        vector<vector<string>> mappings = getMappings();
        if (digits == "") {
            return results;
        }
        recursion(digits, mappings, results, string_so_far, 0);
        return results;
    }

    void recursion(string &digits, vector<vector<string>> &mappings, vector<string> &results, string string_so_far, int idx) {
        if (idx == digits.size()) {
            results.push_back(string_so_far);
            return;
        }
        stringstream obj;
        int digit;
        obj << digits[idx];
        obj >> digit;
        vector<string> digit_mapping = mappings[digit];
        for (int i=0; i<digit_mapping.size(); i++) {
            string_so_far.append(digit_mapping[i]);
            recursion(digits, mappings, results, string_so_far, idx+1);
            string_so_far.pop_back();
        }
    }

    vector<vector<string>> getMappings() {
        vector<vector<string>> mappings;
        vector<string> temp0, temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8, temp9;
        // index - 0
        mappings.push_back(temp0);
        // index - 1
        mappings.push_back(temp1);
        // index - 2
        temp2.push_back("a");
        temp2.push_back("b");
        temp2.push_back("c");
        mappings.push_back(temp2);
        // index - 3
        temp3.push_back("d");
        temp3.push_back("e");
        temp3.push_back("f");
        mappings.push_back(temp3);
        // index - 4
        temp4.push_back("g");
        temp4.push_back("h");
        temp4.push_back("i");
        mappings.push_back(temp4);
        // index - 5
        temp5.push_back("j");
        temp5.push_back("k");
        temp5.push_back("l");
        mappings.push_back(temp5);
        // index - 6
        temp6.push_back("m");
        temp6.push_back("n");
        temp6.push_back("o");
        mappings.push_back(temp6);
        // index - 7
        temp7.push_back("p");
        temp7.push_back("q");
        temp7.push_back("r");
        temp7.push_back("s");
        mappings.push_back(temp7);
        // index - 8
        temp8.push_back("t");
        temp8.push_back("u");
        temp8.push_back("v");
        mappings.push_back(temp8);
        // index - 9
        temp9.push_back("w");
        temp9.push_back("x");
        temp9.push_back("y");
        temp9.push_back("z");
        mappings.push_back(temp9);

        return mappings;
    }
};