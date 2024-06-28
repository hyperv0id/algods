#define SOLU 1

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
#if SOLU == 0
// 记忆化搜索
// https://leetcode.cn/problems/painting-the-walls/submissions/542562233
  typedef long long ll;
  unordered_map<ll, int> cache;
  int paintWalls(vector<int> &cost, vector<int> &time) {
    return dfs(cost, time, time.size() - 1, 0);
  }
  int dfs(vector<int> &cost, vector<int> &time, ll idx, ll time_spent) {
    auto mkid = [idx, time_spent]() { return (idx << 32) + time_spent; };
    if (cache.find(mkid()) != cache.end()) {
      return cache[mkid()];
    } else if (idx < time_spent) {
      // j的状态优化到 [-n, n-1]
      return 0;
    } else if (idx < 0) {
      return 1e9;
    } else {
      int pay = dfs(cost, time, idx - 1, time_spent + time[idx]) + cost[idx];
      int free = dfs(cost, time, idx - 1, time_spent - 1);
      int ans = min(pay, free);
      cache[mkid()] = ans;
      return ans;
    }
  }
#endif

#if SOLU == 1
// 每次能刷 1 + time[i] 个墙，代价cost[i]
// min(cost), time>=n
// 至少型 0-1 背包
// dp[i][j] == 选前i个，time至少为j 的 最小cost
typedef long long ll;
  int paintWalls(vector<int> &cost, vector<int> &time) {
    int n = cost.size();
    vector<int> dp(n + 1, INT_MAX >> 1);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
      auto c = cost[i], t = time[i];
      for (int j = n; j > 0; --j) {
        dp[j] = min(dp[j], dp[max(j - t - 1, 0)] + c);
      }
    }
    return dp[n];
  }
#endif
};

int main(int argc, char *argv[]) {
  Solution s;
  return 0;
}
