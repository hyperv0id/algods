#include <bits/stdc++.h>

using namespace std;

// 739. 每日温度
// https://leetcode.cn/problems/daily-temperatures/submissions/569732686

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    vector<int> ans(temperatures.size());
    stack<int> idx;
    idx.push(temperatures.size() - 1);
    for (int i = temperatures.size() - 2; i >= 0; --i) {
      while (!idx.empty() && temperatures[idx.top()] <= temperatures[i]) {
        idx.pop();
      }
      ans[i] = idx.empty() ? 0 : idx.top() - i;
      idx.push(i);
    }
    return ans;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  return 0;
}
