#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/merge-intervals/submissions/543422314?envType=study-plan-v2&envId=top-100-liked
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(
        intervals.begin(), intervals.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
    vector<vector<int>> ans;
    int begin = intervals[0][0];
    int end = intervals[0][1];
    for (auto &&itv : intervals) {
      if (itv[0] > end) {
        ans.push_back({begin, end});
        begin = itv[0];
      }
      end = max(end, itv[1]);
    }
    ans.push_back({begin, end});
    return ans;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  return 0;
}
