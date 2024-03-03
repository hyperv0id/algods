#include <bits/stdc++.h>
#include <vector>

using namespace std;

// https://leetcode.cn/problems/surrounded-regions/submissions/471233756/
class Solution {
  public:
    constexpr static int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    void solve(vector<vector<char>> &board) {
        auto m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            if (board[i][n - 1] == 'O') {
                dfs(board, i, n - 1);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (board[0][i] == 'O') {
                dfs(board, 0, i);
            }
            if (board[m - 1][i] == 'O') {
                dfs(board, m - 1, i);
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] != '0') {
                    board[i][j] = 'X';
                } else {
                    board[i][j] = 'O';
                }
            }
        }
    }
    void dfs(vector<vector<char>> &board, int x, int y) {
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) {
            return;
        }
        if (board[x][y] != 'O') {
            return;
        }
        board[x][y] = '0';
        int nx, ny;
        for (int i = 0; i < 4; ++i) {
            nx = x + dir[i][0], ny = y + dir[i][1];
            dfs(board, nx, ny);
        }
    }
};
int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
