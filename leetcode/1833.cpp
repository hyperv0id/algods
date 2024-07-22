#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/maximum-ice-cream-bars/submissions/548699388
// 1833. 雪糕的最大数量
class Solution {
public:
  int maxIceCream(vector<int> &costs, int coins) {
    sort(costs.begin(), costs.end());
    int total = 0;
    int cnt = 0;
    for (int n : costs) {
      if (total + n > coins) {
        return cnt;
      }
      total += n;
      cnt++;
    }

    return cnt;
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  return 0;
}
