#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        if (nums.size() == 1) {
            return true;
        }
        vector<int> memo_array;
        for (int i=0; i<nums.size(); i++) {
            memo_array.push_back(-1);
        }
        return recursive(nums, memo_array, 0);
    }
private:
    bool recursive(vector<int> &nums, vector<int> &memo_array, int idx) {
        if (memo_array[idx] < 0) {
            if (idx == nums.size()-1) {
                memo_array[idx] = 1;
            } else {
                int max_size = nums[idx];
                bool possible = 0;
                for (int i=1; i<=max_size; i++) {
                    if (recursive(nums, memo_array, idx+i)) {
                        possible = 1;
                        break;
                    }
                }
                memo_array[idx] = possible;
            }
        }
        if (memo_array[idx] == 1) {
            return true;
        } else {
            return false;
        }
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