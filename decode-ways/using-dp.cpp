#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0) {
            return 0;
        }
        if (s[0] == '0') {
            return 0;
        }
        
        int N = s.size();
        int dp[N];
        for (int i=0; i<N; i++) {
            dp[i] = 0;
        }
        dp[0] = 1;
        for (int i=1; i<N; i++) {
            string one_char, two_char;
            one_char += s[i];
            one_char += '\0';
            two_char += s[i-1];
            two_char += s[i];
            two_char += '\0';
            int one_char_int = stoi(one_char), two_char_int = stoi(two_char);
            if (one_char_int > 0) {
                dp[i] += dp[i-1];
            }
            if (two_char_int > 9 && two_char_int < 27) {
                if (i-2 >= 0) {
                    dp[i] += dp[i-2];
                } else {
                    dp[i] += 1;
                }
            }
        }

        return dp[N-1];
    }
};

int main() {
    Solution sol;

    printf("result -> %d\n\n", sol.numDecodings("12"));
    // printf("%s, %s, %c, %c\n", one_char.c_str(), two_char.c_str(), s[i-1], s[i]);
    // printf("%d, %d, %d\n", dp[i-2], dp[i-1], dp[i]);
}