#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        vector<int> memo_array;
        for (int j=0; j<nums.size()+1; j++) {
            memo_array.push_back(-1);
        }
        memo_array[0] = 0;
        memo_array[1] = nums[0];
        for (int i=1; i<nums.size(); i++) {
            memo_array[i+1] = max(memo_array[i], nums[i] + memo_array[i-1]);
        }
        return memo_array[nums.size()];
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