#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/climbing-stairs/submissions/544402352?envType=study-plan-v2&envId=top-100-liked
// 70. 爬楼梯
class Solution {
public:
  vector<int> ans = vector<int>(50);
  int climbStairs(int n) {
    if (ans[n] != 0)
      return ans[n];
    ans[1] = 1;
    ans[2] = 2;
    for (int i = 3; i <= 45; ++i) {
      ans[i] = ans[i - 1] + ans[i - 2];
    }
    return ans[n];
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  return 0;
}
