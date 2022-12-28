#include<vector>
#include<map>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
    public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        map<string, int> hash_map;
        vector<vector<string>> result;
        int idx=0;
        for (int i=0; i<strs.size(); i++) {
            string hash_map_key = strs[i];
            sort(hash_map_key.begin(), hash_map_key.end());
            if (hash_map.count(hash_map_key) != 0) {
                result[hash_map[hash_map_key]].push_back(strs[i]);
            } else {
                vector<string> temp = {strs[i]};
                result.push_back(temp);
                hash_map[hash_map_key] = idx;
                idx++;
            }
        }
        return result;
    }

};

int main() {
    Solution sol;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result = sol.groupAnagrams(strs);
    for (int i=0; i<result.size(); i++) {
        printf("[ ");
        for (int j=0; j<result[i].size(); j++) {
            printf("%s, ", result[i][j].c_str());
        }
        printf("]\n");
    }
}