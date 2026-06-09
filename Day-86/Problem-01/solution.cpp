#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    void backtrack(int row, int n, vector<string>& board, vector<vector<string>>& ans, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (cols[col] || diag1[row + col] || diag2[row - col + n - 1]) continue;
            board[row][col] = 'Q';
            cols[col] = diag1[row + col] = diag2[row - col + n - 1] = true;
            backtrack(row + 1, n, board, ans, cols, diag1, diag2);
            board[row][col] = '.';
            cols[col] = diag1[row + col] = diag2[row - col + n - 1] = false;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);
        backtrack(0, n, board, ans, cols, diag1, diag2);
        return ans;
    }
};

int main() {
    Solution sol;
    auto res = sol.solveNQueens(4);
    cout << res.size() << endl; // Expected: 2
    return 0;
}
