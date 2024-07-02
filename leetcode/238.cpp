#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/product-of-array-except-self/submissions/543426485?envType=study-plan-v2&envId=top-100-liked
// 除自身以外数组的乘积
// 用前缀和后缀来缓存
class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    vector<int> pre(n), suf(n);
    int tot = 1;
    for (int i = 0; i < n; ++i) {
      pre[i] = tot;
      tot *= nums[i];
    }
    tot = 1;
    for (int i = n - 1; i >= 0; --i) {
      suf[i] = tot;
      tot *= nums[i];
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      ans.emplace_back(pre[i] * suf[i]);
    }
    return ans;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> v{1, 2, 3};
  vector<int> ans = s.productExceptSelf(v);
  for (int n : ans) {
    cout << n << " ";
  }
  return 0;
}
