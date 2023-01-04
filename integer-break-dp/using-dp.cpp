#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n<2) {
            return 0;
        }
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 1;
        for (int i=2; i<n; i++) {
            int max_prod = i;
            int j=i-1;
            while (j>=1) {
                max_prod = max(max_prod, (i-j)*dp[j]);
                j--;
            }
            dp[i] = max_prod;
        }
        int max_prod = 0;
        for (int j=n-1; j>=1; j--) {
            max_prod = max(max_prod, (n-j)*dp[j]);
        }
        return max_prod;
    }
};

int main() {
    Solution sol;
    int n = 4;
    printf("n = [%d], ans = [%d]\n\n", n, sol.integerBreak(n));
}