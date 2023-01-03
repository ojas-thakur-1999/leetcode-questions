#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[nums.size()];
        dp[0] = 1;
        for (int i=1; i<nums.size(); i++) {
            int max_len = 1;
            int j = i-1;
            while (j>=0) {
                if (nums[j] < nums[i]) {
                    max_len = max(max_len, 1+dp[j]);
                }
                j--;
            }
            dp[i] = max_len;
        }
        int max_len = 0;
        for (int i=0; i<nums.size(); i++) {
            max_len = max(max_len, dp[i]);
        }
        return max_len;
    }
};

int main() {
    Solution sol;
    // vector<int> nums = {10,9,2,5,3,7,101,18};
    // vector<int> nums = {0,1,0,3,2,3};
    vector<int> nums = {1,3,6,7,9,4,10,5,6};
    // vector<int> nums = {7,7,7,7,7,7,7};
    // vector<int> nums = {4,10,4,3,8,9};
    printf("%d\n\n", sol.lengthOfLIS(nums));
}