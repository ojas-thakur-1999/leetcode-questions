#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        if (nums.size() == 1) {
            return 0;
        }
        vector<int> memo_array;
        for (int i=0; i<nums.size(); i++) {
            memo_array.push_back(nums.size());
        }
        memo_array[nums.size()-1] = 0;
        for (int i=nums.size()-2; i>=0; i--) {
            int min_jumps = nums.size();
            for (int j=1; j<=nums[i] && i+j <nums.size(); j++) {
                min_jumps = min(min_jumps, 1 + memo_array[i+j]);
            }
            memo_array[i] = min_jumps;
        }
        return memo_array[0];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,1};
    printf("%d\n", sol.jump(nums));
}