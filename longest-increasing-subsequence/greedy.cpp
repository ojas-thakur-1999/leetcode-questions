#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> subarray;
        subarray.push_back(nums[0]);
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] > subarray[subarray.size()-1]) {
                subarray.push_back(nums[i]);
            } else {
                int just_greater_than_idx = findJustGreaterThanIdx(subarray, nums[i]);
                subarray[just_greater_than_idx] = nums[i];
            }
        }
        return subarray.size();
    }
    // this can be done in log(n) time using binary search
    // doing it in o(n) time for now
    int findJustGreaterThanIdx(vector<int> &nums, int target) {
        int found_idx = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] > target) {
                found_idx = i;
                break;
            }
        }
        return found_idx;
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