#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/minimum-path-sum/submissions/466265528/?envType=study-plan-v2&envId=top-interview-150
class Solution {
  public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();

        vector<int> dp(n);
        dp[0] = grid[0][0];
        for (int i = 1; i < grid[0].size(); i++) {
            dp[i] = dp[i - 1] + grid[0][i];
        }

        for (int i = 1; i < grid.size(); i++) {
            dp[0] += grid[i][0];
            for (int j = 1; j < grid[i].size(); j++) {
                dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }
        return dp.back();
    }
};
int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
