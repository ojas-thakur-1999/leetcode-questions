#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int count_with_max_len[nums.size()];
        int dp[nums.size()];
        dp[0] = 1;
        count_with_max_len[0] = 1;
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

            if (max_len == 1) {
                count_with_max_len[i] = 1;
            } else {
                int count_with_max_len_i = 0;
                j = i-1;
                while (j>=0) {
                    if (nums[j] < nums[i] && 1+dp[j] == max_len) {
                        count_with_max_len_i += count_with_max_len[j];
                    }
                    j--;
                }
                count_with_max_len[i] = count_with_max_len_i;
            }
        }
        int max_len = 0;
        for (int i=0; i<nums.size(); i++) {
            max_len = max(max_len, dp[i]);
        }
        
        int count = 0;
        for (int i=0; i<nums.size(); i++) {
            if (dp[i] == max_len) {
                count += count_with_max_len[i];
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    // vector<int> nums = {10,9,2,5,3,7,101,18};
    // vector<int> nums = {0,1,0,3,2,3};
    // vector<int> nums = {1,3,6,7,9,4,10,5,6};
    vector<int> nums = {1,2,4,3,5,4,7,2};
    // vector<int> nums = {2,2,2,2,2};
    // vector<int> nums = {1,3,5,4,7};
    printf("%d\n\n", sol.findNumberOfLIS(nums));
}