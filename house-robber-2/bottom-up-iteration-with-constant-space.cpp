#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int rob(vector<int> &houses) {
        if (houses.size() == 1) {
            return houses[0];
        }
        return max(houseRobber(houses, 1, houses.size()-1), houseRobber(houses, 0, houses.size()-2));
    }
private:
    int houseRobber(vector<int> &houses, int start, int end) {
        if (end < start) {
            return 0;
        }
        int prev = 0;
        int curr = houses[start];
        int next = max(curr, houses[start] + prev);
        for (int i=start+1; i<=end; i++) {
            next = max(curr, houses[i] + prev);
            prev = curr;
            curr = next;
        }
        return next;
    }
};

int main() {
    Solution sol;
    vector<int> houses2 = {2,1,2,1,2};
    int res2 = sol.rob(houses2);
    printf("res2 - %d\n", res2);
};