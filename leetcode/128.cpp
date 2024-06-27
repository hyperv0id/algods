#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/longest-consecutive-sequence/description/?envType=study-plan-v2&envId=top-100-liked
// 最长连续序列 
// https://leetcode.cn/problems/longest-consecutive-sequence/submissions/388239410?envType=study-plan-v2&envId=top-100-liked
class Solution {
public:
  unordered_map<int, int> parent;

  int longestConsecutive(vector<int> &nums) {
    for (auto &&n : nums) {
      put(n);
    }
    int ans = 0;
    for (auto &&n : nums) {
      int f = find(n);
      // cout << n << "\t" << f << endl;
      ans = max(find(n) - n + 1, ans);
    }
    return ans;
  }
  int find(int n) {
    if (parent[n] == n) {
      return n;
    }
    parent[n] = find(parent[n]);
    return parent[n];
  }
  void put(int n) {
    if (parent.count(n - 1)) {
      parent[n - 1] = n;
    }
    parent[n] = parent.count(n + 1) ? n + 1 : n;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  return 0;
}
