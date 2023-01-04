#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusting(n, 0);
        vector<int> trusted_by(n, 0);
        for (int i=0; i<trust.size(); i++) {
            trusting[trust[i][0]-1]++;
            trusted_by[trust[i][1]-1]++;
        }
        for (int i=0; i<n; i++) {
            if (trusted_by[i] == n-1 && trusting[i] == 0) {
                return i+1;
            }
        }
        return -1;
    }
};

int main() {}