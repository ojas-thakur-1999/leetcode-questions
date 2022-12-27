#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

bool sortSecond(vector<int>& v1, vector<int>& v2) {
    return v1[1] < v2[1];
}

class Solution {
    public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector< vector<int>> sorted_candidates;
        for (int i=0; i<candidates.size(); i++) {
            vector<int> temp = {i, candidates[i]};
            sorted_candidates.push_back(temp);
        }
        sort(sorted_candidates.begin(), sorted_candidates.end(), sortSecond);
        vector< vector<int>> result;
        vector<int> indices;
        usingRecursion(sorted_candidates, target, 0, indices, 0, result);
        return result;
    }

    void usingRecursion(vector< vector<int>>& candidates, int target, int sum_so_far, vector<int> indices_so_far, int idx, vector< vector<int>> &result) {
        for (int i=idx; i<candidates.size(); i++) {
            int sum = sum_so_far + candidates[i][1];
            if (sum == target) {
                indices_so_far.push_back(i);
                vector<int> values;
                for (int j=0; j<indices_so_far.size(); j++) {
                    values.push_back(candidates[indices_so_far[j]][1]);
                }
                result.push_back(values);
                break;
            } else if (sum_so_far > target) {
                break;
            }
            indices_so_far.push_back(i);
            usingRecursion(candidates, target, sum, indices_so_far, i, result);
            indices_so_far.pop_back();
        }
    }
};