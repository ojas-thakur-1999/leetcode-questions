#include<string>
#include<vector>
using namespace std;

class Solution {
    public:
    string longestPalindrome(string &s) {
        int longestPalindromeLen = 0;
        int longestPalindromeParity = 0;
        int longestPalindromeMidptIdx = 0;
        vector<vector<int>> occurence_matrix = getOccurenceMatrix(s);
        for (int i=0; i<s.size(); i++) {
            for (int j=0; j<s.size(); j++) {
                vector<int> res = getLongestPalindrome(occurence_matrix, i, j);
                if (res[1] > longestPalindromeLen) {
                    longestPalindromeLen = res[1];
                    longestPalindromeParity = res[0];
                    longestPalindromeMidptIdx = j;
                }
            }
        }
        string result;
        if (longestPalindromeParity == -1) {
            for (int i=longestPalindromeMidptIdx - (longestPalindromeLen/2); i<=longestPalindromeMidptIdx + (longestPalindromeLen/2-1); i++) {
                result += s[i];
            }
        } else if (longestPalindromeParity == 1) {
            for (int i=longestPalindromeMidptIdx - (longestPalindromeLen/2); i<=longestPalindromeMidptIdx + (longestPalindromeLen/2); i++) {
                result += s[i];
            }
        }
        return result;
    }

    private:
    vector<int> getLongestPalindrome(vector<vector<int>> &matrix, int x, int y) {
        vector<int> result = {0, 0};
        if (matrix[x][y] == 1) {
            int len1 = getSurroundingSquareLen(matrix, x-1, y-1, x-1, y+1, x+1, y+1, x+1, y-1, 1);
            len1 = 2*len1 - 1;
            int len2 = getSurroundingSquareLen(matrix, x, y-1, x, y, x+1, y, x+1, y-1, 0);
            len2 = 2*len2;
            if (len1 > len2) {
                result[0] = 1;
                result[1] = len1;
            } else {
                result[0] = -1;
                result[1] = len2;
            }
            return result;
        }
        return result;
    }

    int getSurroundingSquareLen(vector<vector<int>> &matrix, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int len_so_far) {
        if (isInvalid(x1, y1, matrix.size()) || isInvalid(x2, y2, matrix.size()) || isInvalid(x3, y3, matrix.size()) || isInvalid(x4, y4, matrix.size())) {
            return len_so_far;
        }

        if (matrix[x1][y1] == 1 && matrix[x2][y2] == 1 && matrix[x3][y3] == 1 && matrix[x4][y4] == 1) {
            return getSurroundingSquareLen(matrix, x1-1, y1-1, x2-1, y2+1, x3+1, y3+1, x4+1, y4-1, len_so_far+1);
        }

        return len_so_far;
    }

    bool isInvalid(int x, int y, int n) {
        return (x < 0 || x >= n || y < 0 || y >= n);
    }

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
    string str = "bcb";
    string ans = sol.longestPalindrome(str);
    printf("input -> \"%s\"\n", str.c_str());
    printf("longestPalindrome -> \"%s\"\n", ans.c_str());
}