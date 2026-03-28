#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    bool backtrack(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        if (idx == word.length()) return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[idx]) return false;
        char temp = board[i][j];
        board[i][j] = '*';
        bool res = backtrack(board, word, i+1, j, idx+1) ||
                   backtrack(board, word, i-1, j, idx+1) ||
                   backtrack(board, word, i, j+1, idx+1) ||
                   backtrack(board, word, i, j-1, idx+1);
        board[i][j] = temp;
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (backtrack(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};

int main() {
    return 0;
}
