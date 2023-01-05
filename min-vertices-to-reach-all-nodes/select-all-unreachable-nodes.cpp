#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        int in_degree[n];
        for (int i=0; i<n; i++) {
            in_degree[i] = 0;
        }
        for (int i=0; i<edges.size(); i++) {
            in_degree[edges[i][1]]++;
        }
        vector<int> result;
        for (int i=0; i<n; i++) {
            if (in_degree[i] == 0) {
                result.push_back(i);
            }
        }
        return result;
    }
};

int main() {}