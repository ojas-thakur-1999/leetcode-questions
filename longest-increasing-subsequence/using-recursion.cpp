#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int max_len = 0;
        for (int i=0; i<nums.size(); i++) {
            max_len = max(max_len, longestEndingAt(nums, i));
        }
        return max_len;
    }
private:
    int longestEndingAt(vector<int> &nums, int end) {
        if (end == 0) {
            return 1;
        }
        int max_len = 1;
        int idx = end - 1;
        while (idx >= 0) {
            if (nums[idx] < nums[end]) {
                max_len = max(max_len, 1+longestEndingAt(nums, idx));
            }
            idx -= 1;
        }
        return max_len;
    }
};

int main() {
    Solution sol;
    // vector<int> nums = {10,9,2,5,3,7,101,18};
    // vector<int> nums = {0,1,0,3,2,3};
    // vector<int> nums = {7,7,7,7,7,7,7};
    vector<int> nums = {4,10,4,3,8,9};
    printf("%d\n\n", sol.lengthOfLIS(nums));
}