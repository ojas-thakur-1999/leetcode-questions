#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        if (nums.size() < 2) {
            return 0;
        }
        // currentMax will store the max node reachable in current level
        // while iterating through all nodes in current level, we will keep updating nextMax
        // i will reach currentMax when this level ends and then we set currentMax to nextMax
        // this will iterate i over all nodes of next level
        // we should stop when nextMax >= last node (i.e. n-1) and return the level (each level represents a step)
        int level=0, currentMax=0, nextMax=0, i=0;
        while(currentMax - i + 1) {
            level++;
            for (; i<= currentMax; i++) {
                nextMax = max(nextMax, i+nums[i]);
                if (nextMax >= nums.size()-1) {
                    return level;
                }
            }
            currentMax = nextMax;
        }
        return 0;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,1};
    printf("%d\n", sol.jump(nums));
}