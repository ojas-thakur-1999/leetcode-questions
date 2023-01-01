#include<string>
#include<vector>
using namespace std;

class Solution {
    public:
    string longestPalindrome(string &s) {
        vector<vector<int>> occurence_matrix = getOccurenceMatrix(s);
        int len = s.size();
        int max_len = 1;
        int max_idx = 0;
        for (int n=0; n<2*len - 1; n++) {
            int size = 1;
            if (n < len) {
                size = n+1;
            } else {
                size = 2*len-1-n;
            }
            int pali_len = 0;
            if (n%2==0) {
                pali_len += 1;
                for (int i=1; i<=size/2; i++) {
                    if (occurence_matrix[n/2 + i][n/2 - i] == 1 && occurence_matrix[n/2 - i][n/2 + i] == 1) {
                        pali_len += 2;
                    } else {
                        break;
                    }
                }
            } else {
                for (int i=0; i<size/2; i++) {
                    if (occurence_matrix[n/2 + 1 + i][n/2 - i] == 1 && occurence_matrix[n/2 - i][n/2 + 1 + i] == 1) {
                        pali_len += 2;
                    } else {
                        break;
                    }
                }
            }
            if (pali_len > max_len) {
                max_len = pali_len;
                max_idx = n;
            }
        }
        string result;
        if (max_idx%2==1) {
            for (int i=max_idx/2 - max_len/2; i<= max_idx/2 + max_len/2; i++) {
                result += s[i];
            }
        } else {
            for (int i=max_idx/2 - max_len/2; i<= max_idx/2 + max_len/2; i++) {
                result += s[i];
            }
        }
        return result;
    }

    private:
    vector<vector<int>> getOccurenceMatrix(string &s) {
        vector<vector<int>> result;
        for (int i=0; i<s.size(); i++) {
            vector<int> temp;
            for (int j=0; j<s.size(); j++) {
                if (s[i] == s[j]) {
                    temp.push_back(1);
                } else {
                    temp.push_back(0);
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};

int main() {
    Solution sol;
    string str = "aaaaaacb";
    string ans = sol.longestPalindrome(str);
    printf("input -> \"%s\"\n", str.c_str());
    printf("longestPalindrome -> \"%s\"\n", ans.c_str());
}