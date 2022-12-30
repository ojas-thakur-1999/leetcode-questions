#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        if (nums.size() == 1) {
            return true;
        }
        vector<bool> memo_array;
        for (int i=0; i<nums.size(); i++) {
            memo_array.push_back(false);
        }
        memo_array[nums.size()-1] = true;
        for (int i=nums.size()-2; i>=0 ;i--) {
            bool is_possible = false;
            for (int j=1; j<=nums[i]; j++) {
                is_possible = memo_array[i+j];
                if (is_possible) {
                    break;
                }
            }
            memo_array[i] = is_possible;
        }
        return memo_array[0];
    }
};

int main() {
    Solution sol;

    // vector<int> nums = {2,3,1,1,4};
    vector<int> nums = {3,2,1,0,4};
    
    if (sol.canJump(nums)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
}