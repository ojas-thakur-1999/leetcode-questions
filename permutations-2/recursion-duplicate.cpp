#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution () {
        return;
    }

    vector< vector<int>> permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector< vector<int>> res;
        recursion(nums, nums.size(), res, 0);
        return res;
    }

    void recursion(vector<int> nums, int N, vector< vector<int>>& result, int idx) {
        if (idx == N-1) {
            result.push_back(nums);
            return;
        }

        for (int k=idx; k<N; k++) {
            if (k == idx || nums[k] != nums[idx]) {
                swap(nums[idx], nums[k]);
                recursion(nums, N, result, idx+1);
            }
        }
    }
    
};

int main() {
    int N = 3;
    vector<int> nums;
    for (int i=0; i<N; i++) {
        nums.push_back(0);
    }

    Solution sol;

    int arr1[N] = {1,1,2};
    for (int i=0; i<N; i++) {
        nums[i] = arr1[i];
    }
    vector< vector<int>> res1 = sol.permuteUnique(nums);
    printf("%d\n", res1.size());
    for (int i=0; i<res1.size(); i++) {
        printf("%d, %d, %d\n", res1[i][0], res1[i][1], res1[i][2]);
    }

    // int arr2[N] = {1,2,3};
    // for (int i=0; i<N; i++) {
    //     nums[i] = arr2[i];
    // }
    // vector< vector<int>> res2 = sol.permuteUnique(nums);
    // for (int i=0; i<res2.size(); i++) {
    //     printf("%d, %d, %d\n", res2[i][0], res2[i][1], res2[i][2]);
    //     // printf("%s\n", getVectorString(res2[i]));
    // }
}