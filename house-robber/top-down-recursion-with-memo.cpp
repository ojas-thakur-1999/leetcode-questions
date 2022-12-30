#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int rob(vector<int> &nums) {
        vector<int> memo_array;
        for (int j=0; j<nums.size(); j++) {
            memo_array.push_back(-1);
        }
        return robRecursive(nums, memo_array, nums.size()-1);
    }
private:
    int robRecursive(vector<int> &nums, vector<int> &memo_array, int idx) {
        if (idx < 0) {
            return 0;
        }
        if (memo_array[idx] < 0) {
            memo_array[idx] = max(nums[idx] + robRecursive(nums, memo_array, idx-2), robRecursive(nums, memo_array, idx-1));
        }
        return memo_array[idx];
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