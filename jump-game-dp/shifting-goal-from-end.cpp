#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        if (nums.size() == 1) {
            return true;
        }
        int last = nums.size()-1;
        for (int i=nums.size()-2; i>=0; i--) {
            if (nums[i]+i >= last) {
                last = i;
            }
        }
        return last == 0;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2,3,1,1,4};
    // vector<int> nums = {3,2,1,0,4};
    
    if (sol.canJump(nums)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
}