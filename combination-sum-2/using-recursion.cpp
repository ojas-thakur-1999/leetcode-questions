#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> prev_visited_nodes;
        recursive(candidates, target, result, prev_visited_nodes, 0);
        return result;
    }

    void recursive(vector<int>& sorted_candidates, int target, vector<vector<int>>& result, vector<int> prev_visited_nodes, int order) {
        if (target == 0) {
            result.push_back(prev_visited_nodes);
            return;
        }
        for (int i=order; i<sorted_candidates.size(); i++) {
            if (sorted_candidates[i] > target) {
                return;
            }
            if (i > 0 && i != order && sorted_candidates[i] == sorted_candidates[i-1]) {
                continue;
            }
            prev_visited_nodes.push_back(sorted_candidates[i]);
            recursive(sorted_candidates, target-sorted_candidates[i], result, prev_visited_nodes, i+1);
            prev_visited_nodes.pop_back();
        }
    }
};