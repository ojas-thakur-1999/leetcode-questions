#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

// to sort in ascending order
bool func(int x, int y) {
    return (x <= y);
}

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        sort(coins.begin(), coins.end(), func);
        // we will store in an array, the min number of coins required to reach this amount
        int dp[amount+1];
        dp[0] = 0;
        for (int i=1; i<amount+1; i++) {
            int min_ways = amount+1;
            for (int j=0; j<coins.size(); j++) {
                if (i < coins[j]) {
                    break;
                }
                if (dp[i-coins[j]] >= 0) {
                    min_ways = min(min_ways, 1+dp[i-coins[j]]);
                }
            }
            if (min_ways == amount+1) {
                dp[i] = -1;
            } else {
                dp[i] = min_ways;
            }
        }
        return dp[amount];
    }
};

int main() {
    Solution sol;
    vector<int> coins = {1,2,5};
    int target = 11;
    // vector<int> coins = {1};
    // int target = 0;
    printf("%d\n\n", sol.coinChange(coins, target));
}