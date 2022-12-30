#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int n, int m) {
        if (m<=0 || n<=0) {
            return -1;
        }
        vector<vector<int>> memo_arr;
        for (int i=0; i<n; i++) {
            vector<int> temp;
            for (int j=0; j<m; j++) {
                temp.push_back(-1);
            }
            memo_arr.push_back(temp);
        }
        return recursion(memo_arr, n-1, m-1);
    }
private:
    int recursion(vector<vector<int>> &memo_arr, int n, int m) {
        if (memo_arr[n][m] < 0) {
            if (n==0 || m==0) {
                memo_arr[n][m] = 1;
            } else {
                int ways_down = recursion(memo_arr, n-1, m);
                int ways_right = recursion(memo_arr, n, m-1);
                memo_arr[n][m] = ways_right + ways_down;
            }
        }
        return memo_arr[n][m];
    }
};

int main() {
    Solution sol;
    printf("%d\n", sol.uniquePaths(3,7));
}