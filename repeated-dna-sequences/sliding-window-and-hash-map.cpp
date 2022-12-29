#include<map>
#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
    public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if (s.size() < 10) {
            return result;
        }
        map<string, int> hash_map;
        char buffer[11];
        buffer[10] = '\0';
        for (int i=0; i<10; i++) {
            buffer[i] = s[i];
        }
        string map_key = buffer;
        if (hash_map.count(map_key) == 0) {
            hash_map[map_key] = 1;
        } else {
            hash_map[map_key] += 1;
        }
        for (int i=1; i<=s.size()-10; i++) {
            buffer[0] = buffer[1];
            buffer[1] = buffer[2];
            buffer[2] = buffer[3];
            buffer[3] = buffer[4];
            buffer[4] = buffer[5];
            buffer[5] = buffer[6];
            buffer[6] = buffer[7];
            buffer[7] = buffer[8];
            buffer[8] = buffer[9];
            buffer[9] = s[i+9];
            map_key = buffer;
            if (hash_map.count(map_key) == 0) {
                hash_map[map_key] = 1;
            } else {
                hash_map[map_key] += 1;
                if (hash_map[map_key] == 2) {
                    result.push_back(map_key);
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> res = sol.findRepeatedDnaSequences(s);
    for (int i=0; i<res.size(); i++) {
        printf("%s\n", res[i].c_str());
    }
}