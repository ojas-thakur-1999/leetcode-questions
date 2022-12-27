#include<vector>
#include<string>
using namespace std;

string getVectorString(vector<int> &vec) {
    string str;
    for (int i=0; i<vec.size(); i++) {
        str = str.append(to_string(vec[i]));
    }
    return str;
}

class Solution{
public:
    
    Solution(){
        return;
    }

    vector< vector<int>> permuteUnique(vector<int>& nums) {
        vector< vector<int>> result;
        vector<int> pattern_so_far;
        permutationsRecursive(nums, result, pattern_so_far);
        return result;
    }

private:

    void permutationsRecursive(vector<int>& nums, vector< vector<int>>& result, vector<int> pattern_so_far) {
        if (nums.size() == pattern_so_far.size()) {
            result.push_back(convertIndicesToValues(pattern_so_far, nums));
            return;
        }
        string s = getVectorString(pattern_so_far);
        for (int i=0; i<nums.size(); i++){
            bool index_used = false;
            for (int j=0; j<pattern_so_far.size(); j++) {
                if ((i == pattern_so_far[j])) {
                    index_used = true;
                    break;
                }
            }
            if (!index_used) {
                pattern_so_far.push_back(i);
                permutationsRecursive(nums, result, pattern_so_far);
                pattern_so_far.pop_back();
            }
        }
    }

    vector<int> convertIndicesToValues(vector<int>& indices, vector<int>& nums) {
        vector<int> result;
        for (int i=0; i<indices.size(); i++) {
            result.push_back(nums[indices[i]]);
        }
        return result;
    }

};

int main() {
    int N = 3;
    vector<int> nums;
    for (int i=0; i<N; i++) {
        nums.push_back(0);
    }

    Solution sol;

    // int arr1[N] = {1,1,2};
    // for (int i=0; i<N; i++) {
    //     nums[i] = arr1[i];
    // }
    // vector< vector<int>> res1 = sol.permuteUnique(nums);
    // printf("%d\n", res1.size());
    // for (int i=0; i<res1.size(); i++) {
    //     printf("%d, %d, %d\n", res1[i][0], res1[i][1], res1[i][2]);
    // }

    int arr2[N] = {1,2,3};
    for (int i=0; i<N; i++) {
        nums[i] = arr2[i];
    }
    vector< vector<int>> res2 = sol.permuteUnique(nums);
    for (int i=0; i<res2.size(); i++) {
        printf("%d, %d, %d\n", res2[i][0], res2[i][1], res2[i][2]);
        // printf("%s\n", getVectorString(res2[i]));
    }
}