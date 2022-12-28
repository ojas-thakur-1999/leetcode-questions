#include<string>
#include<vector>
using namespace std;

class Solution {
    public:
    vector<string> generateParenthesis(int n) {
        vector<string> result; 
        if (n == 0) {
            return result;
        }
        string pattern_so_far;
        recursive(n, result, pattern_so_far, 0, 0);
        return result;
    }

    void recursive(int n, vector<string>& results, string pattern_so_far, int num_left, int num_right) {
        if (num_left == n && num_right == n) {
            results.push_back(pattern_so_far);
            return;
        }

        if (num_left < n) {
            pattern_so_far.append("(");
            recursive(n, results, pattern_so_far, num_left+1, num_right);
            pattern_so_far.pop_back();
        }

        if (num_right < n and num_left - num_right > 0) {
            pattern_so_far.append(")");
            recursive(n, results, pattern_so_far, num_left, num_right+1);
            pattern_so_far.pop_back();
        }
    }
};