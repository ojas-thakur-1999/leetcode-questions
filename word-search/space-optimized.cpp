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
                if (findRecursive(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool findRecursive(vector<vector<char>> &board, string &word, int x, int y, int idx) {
        if (board[x][y] != word[idx]) {
            return false;
        }

        if (idx == word.size()-1) {
            return true;
        }

        int M = board.size();
        int N = board[0].size();

        char temp = board[x][y];
        board[x][y] = '#';

        bool found = (x > 0 && findRecursive(board, word, x-1, y, idx+1))
            || (y < N-1 && findRecursive(board, word, x, y+1, idx+1))
            || (x < M-1 && findRecursive(board, word, x+1, y, idx+1))
            || (y > 0 && findRecursive(board, word, x, y-1, idx+1));
        
        board[x][y] = temp;

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
    string word3 = "ABCEFSADEESE";
    bool result3 = sol.exist(board, word3);
    cout<<result3<<endl;
}