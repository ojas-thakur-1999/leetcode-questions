#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixes(nums.size());
        vector<int> suffixes(nums.size());

        prefixes[0] = nums[0];
        for (int i=1; i<nums.size(); i++) {
            prefixes[i] = prefixes[i-1]*nums[i];
        }

        suffixes[nums.size()-1] = nums[nums.size()-1];
        for (int i=nums.size()-2; i>=0; i--) {
            suffixes[i] = suffixes[i+1]*nums[i];
        }

        vector<int> result(nums.size());
        result[0] = suffixes[1];
        result[nums.size()-1] = prefixes[nums.size()-2];
        for (int i=1; i<nums.size()-1; i++) {
            result[i] = prefixes[i-1]*suffixes[i+1];
        }

        return result;
    }
};

int main() {
    vector<int> test = {1,2,3,4};
    Solution s;
    vector<int> result = s.productExceptSelf(test);
    for (int i=0; i<result.size(); i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}