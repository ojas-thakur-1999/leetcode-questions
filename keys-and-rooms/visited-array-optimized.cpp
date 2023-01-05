#include<vector>
#include<string>
#include<iostream>
#include<list>
#include<queue>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        
        queue<int> li;
        li.push(0);
        
        bool visited[n];
        for (int i=1; i<n; i++) {
            visited[i] = false;
        }
        visited[0] = true;
        
        while (!li.empty()) {
            int node = li.front();
            li.pop();
            for (int i=0; i<rooms[node].size(); i++) {
                if (!visited[rooms[node][i]]) {
                    visited[rooms[node][i]] = true;
                    li.push(rooms[node][i]);
                }
            }
        }

        for (int i=0; i<n; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {}