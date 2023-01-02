#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        if (nums.size() < 3) {
            return 0;
        }

        int diff_arr[nums.size()];
        diff_arr[0] = 0;
        for (int i=1; i<nums.size(); i++) {
            diff_arr[i] = nums[i]-nums[i-1];
        }

        int latest_contiguous_segment_length = 1;
        int number_of_arithmetic_slices = 0;
        for (int i=2; i<nums.size(); i++) {
            if (diff_arr[i] == diff_arr[i-1]) {
                latest_contiguous_segment_length += 1;
                if (latest_contiguous_segment_length >= 2) {
                    number_of_arithmetic_slices += latest_contiguous_segment_length-1;
                }
            } else {
                latest_contiguous_segment_length = 1;
            }
        }

        return number_of_arithmetic_slices;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1,1,1,1};

    printf("count -> %d\n\n", sol.numberOfArithmeticSlices(nums));
}