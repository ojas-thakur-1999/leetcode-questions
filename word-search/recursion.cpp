#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution {
    public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) {
            return false;
        }
        int M = board.size();
        int N = board[0].size();
        for (int i=0; i<M; i++) {
            for (int j=0; j<N; j++) {
                vector<vector<int>> visited;
                for (int k=0; k<M; k++) {
                    vector<int> temp;
                    for (int l=0; l<N; l++) {
                        temp.push_back(0);
                    }
                    visited.push_back(temp);
                }
                if (findRecursive(board, word, visited, i, j, 0)) {
                    return true;
                }
                visited.clear();
            }
        }
        return false;
    }

    bool findRecursive(vector<vector<char>> &board, string &word, vector<vector<int>> &visited, int x, int y, int idx) {
        if (board[x][y] != word[idx]) {
            return false;
        }

        visited[x][y] = 1;

        if (idx == word.size()-1) {
            return true;
        }

        int M = board.size();
        int N = board[0].size();

        bool found = (x > 0 && visited[x-1][y] == 0 && findRecursive(board, word, visited, x-1, y, idx+1))
            || (y < N-1 && visited[x][y+1] == 0 && findRecursive(board, word, visited, x, y+1, idx+1))
            || (x < M-1 && visited[x+1][y] == 0 && findRecursive(board, word, visited, x+1, y, idx+1))
            || (y > 0 && visited[x][y-1] == 0 && findRecursive(board, word, visited, x, y-1, idx+1));
        
        if (!found) {
            visited[x][y] = 0;
        }
        return found;
    }

};

int main() {
    Solution sol;
    vector<char> row1 = {'A','B','C','E'};
    vector<char> row2 = {'S','F','E','S'};
    vector<char> row3 = {'A','D','E','E'};
    vector<vector<char>> board = {row1, row2, row3};
    // string word1 = "ABCCED";
    // bool result1 = sol.exist(board, word1);
    // cout<<result1<<endl;
    // string word2 = "SEE";
    // bool result2 = sol.exist(board, word2);
    // cout<<result2<<endl;
    string word3 = "ABCEFSADEESA";
    bool result3 = sol.exist(board, word3);
    cout<<result3<<endl;
}