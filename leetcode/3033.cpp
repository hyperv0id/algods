#include <bits/stdc++.h>

using namespace std;
// https://leetcode.cn/problems/modify-the-matrix/submissions/544171880
// 3033. 修改矩阵

class Solution {
public:
  vector<vector<int>> modifiedMatrix(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> mval(n);
    for (int i = 0; i < n; ++i) {
      int big = -1;
      for (int j = 0; j < m; ++j) {
        big = max(big, matrix[j][i]);
      }
      mval[i] = big;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if(matrix[j][i] == -1)matrix[j][i] = mval[i];
      }
    }
    return matrix;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  return 0;
}
