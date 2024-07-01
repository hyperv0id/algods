#include <bits/stdc++.h>
#include <functional>

using namespace std;

class Solution {
public:
  int maximalPathQuality(vector<int> &values, vector<vector<int>> &edges,
                         int maxTime) {
    int n = values.size();
    vector<vector<pair<int, int>>> tab(n);
    for (auto &&e : edges) {
      tab[e[0]].emplace_back(e[1], e[2]);
      tab[e[1]].emplace_back(e[0], e[2]);
    }
    vector<bool> vis(n);
    vis[0] = true;
    int ans = 0;
    function<void(int, int, int)> dfs = [&](int p, int t, int val) {
      if (p == 0) {
        ans = max(ans, val);
      }
      for (auto &&[np, d] : tab[p]) {
        if (t + d <= maxTime) {
          if (!vis[np]) {
            vis[np] = true;
            dfs(np, t + d, val + values[np]);
            vis[np] = false;
          } else {
            dfs(np, t + d, val);
          }
        }
      }
    };

    dfs(0, 0, values[0]);
    return ans;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  return 0;
}
