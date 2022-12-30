#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int n, int m) {
        if (m<=0 || n<=0) {
            return -1;
        }
        vector<vector<int>> dp;
        for (int i=0; i<n; i++) {
            vector<int> temp;
            for (int j=0; j<m; j++) {
                temp.push_back(1);
            }
            dp.push_back(temp);
        }
        for (int i=1; i<n; i++) {
            for (int j=1; j<m; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};

int main() {
    Solution sol;
    printf("%d\n", sol.uniquePaths(3,7));
}