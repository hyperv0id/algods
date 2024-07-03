#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/search-a-2d-matrix-ii/submissions/543704354?envType=study-plan-v2&envId=top-100-liked
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    auto isin = [&matrix](int x, int y) {
      return x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size();
    };
    int x = 0, y = matrix[0].size() - 1;
    while (isin(x, y)) {
      if (matrix[x][y] > target)
        y--;
      else if (matrix[x][y] > target)
        x++;
      else
        return true;
    }
    return false;
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  return 0;
}
