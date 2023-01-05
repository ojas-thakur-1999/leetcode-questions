#include<vector>
#include<string>
#include<iostream>
#include<list>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        
        list<int> li;
        li.push_back(0);
        
        bool visited[n];
        for (int i=1; i<n; i++) {
            visited[i] = false;
        }
        visited[0] = true;
        
        int visited_count = 0;
        visited_count++;
        while (!li.empty()) {
            int node = li.front();
            li.pop_front();
            for (int i=0; i<rooms[node].size(); i++) {
                if (!visited[rooms[node][i]]) {
                    visited[rooms[node][i]] = true;
                    li.push_back(rooms[node][i]);
                    visited_count++;
                }
            }
            if (visited_count == n) {
                return true;
            }
        }
        return false;
    }
};

int main() {}