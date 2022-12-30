#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int prev = 0;
        int curr = nums[0];
        int next = max(curr, nums[0] + prev);
        for (int i=1; i<nums.size(); i++) {
            next = max(curr, nums[i] + prev);
            prev = curr;
            curr = next;
        }
        return next;
    }
};

int main() {
    Solution sol;
    // vector<int> houses1 = {1,2,3,1};
    // int res1 = sol.rob(houses1);
    // printf("res1 - %d\n", res1);
    
    vector<int> houses2 = {2,1,2,1,2};
    int res2 = sol.rob(houses2);
    printf("res2 - %d\n", res2);
}