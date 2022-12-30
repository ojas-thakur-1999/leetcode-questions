#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<vector<int>> memo_array;
        for (int i=0; i<nums.size(); i++) {
            vector<int> temp;
            for (int j=0; j<nums.size(); j++) {
                temp.push_back(-1);
            }
            memo_array.push_back(temp);
        }
        return max(findMaxSumRecursive(nums, memo_array, 0, nums.size()-2), findMaxSumRecursive(nums, memo_array, 1, nums.size()-1));
    }
private:
    int findMaxSumRecursive(vector<int> &nums, vector<vector<int>> &memo_array, int start, int end) {
        int start_idx = getArrayIdxFromValue(start, nums.size());
        int end_idx = getArrayIdxFromValue(end, nums.size());
        if (memo_array[start_idx][end_idx] < 0) {
            if (start > end) {
                memo_array[start_idx][end_idx] = 0;
            } else if (start == end) {
                memo_array[start_idx][end_idx] = nums[start_idx];
            } else {
                int max_sum = 0;
                for (int i=start; i<=end; i++) {
                    int curr_sum = findMaxSumRecursive(nums, memo_array, start, i-2)
                        + nums[getArrayIdxFromValue(i, nums.size())]
                        + findMaxSumRecursive(nums, memo_array, i+2, end);
                    if (curr_sum > max_sum) {
                        max_sum = curr_sum;
                    }
                }
                memo_array[start_idx][end_idx] = max_sum;
            }
        }
        return memo_array[start_idx][end_idx];
    }

    int getArrayIdxFromValue(int value, int array_size) {
        while (value < 0) {
            value += array_size;
        }
        return value % array_size;
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