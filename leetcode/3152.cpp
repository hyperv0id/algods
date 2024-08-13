#include <bits/stdc++.h>

using namespace std;
// https://leetcode.cn/problems/special-array-ii/submissions/554999616
class Solution {
public:
  vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size();
    vector<int> nexts(n, 0);
    auto foo = [&nums](int pos) {
      return (nums[pos] & 1) != (nums[pos - 1] & 1);
    };
    // init
    for (int i = 0; i < n;) {
      int j = i+1;
      while (j < n && foo(j)) {
        j++;
      }
      for (int p = i; p < j; p++)
        nexts[p] = j-1;
      i = j;
    }
    // calc
    vector<bool> ans;
    for (auto &&q : queries) {
      ans.push_back(q[1] <= nexts[q[0]]);
    }
    return ans;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  return 0;
}
