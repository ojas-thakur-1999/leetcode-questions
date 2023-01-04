#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

bool func(int x, int y) {
    return (x >= y);
}

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        sort(coins.begin(), coins.end(), func);
        return checkRecursive(coins, 0, amount);
    }
private:
    int checkRecursive(vector<int> &coins, int idx, int target) {
        if (target < 0) {
            return -1;
        } else if (target == 0) {
            return 0;
        } else if (idx == coins.size()) {
            return -1;
        }

        int min_ways = target;
        bool found = false;
        for (int i=target/coins[idx]; i>=0; i--) {
            int ways = checkRecursive(coins, idx+1, target-(i*coins[idx]));
            if (ways >= 0) {
                found = true;
                min_ways = min(min_ways, ways+i);
            }
        }
        if (found) {
            return min_ways;
        } else {
            return -1;
        }
    }
};

int main() {
    Solution sol;
    // vector<int> coins = {1,2,5};
    // int target = 11;
    vector<int> coins = {1};
    int target = 0;
    printf("%d\n\n", sol.coinChange(coins, target));
}