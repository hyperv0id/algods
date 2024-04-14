#include <bits/stdc++.h>

using namespace std;

class NumMatrix {
  public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.size() > 0) {
            mat.resize(matrix.size(), vector<int>(matrix[0].size() + 1));
            for (int i = 0; i < matrix.size(); i++) {
                for (int j = 0; j < matrix[0].size(); j++) {
                    mat[i][j + 1] = mat[i][j] + matrix[i][j];
                }
            }
        }
    }
    vector<vector<int>> mat;
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ret = 0;
        for (int i = row1; i <= row2; i++) {
            ret += mat[i][col2 + 1] - mat[i][col1];
        }
        return ret;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
