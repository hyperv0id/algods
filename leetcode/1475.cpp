#include <bits/stdc++.h>

using namespace std;

// 1475. 商品折扣后的最终价格
// https://leetcode.cn/problems/final-prices-with-a-special-discount-in-a-shop/submissions/569734847
class Solution {
public:
  vector<int> finalPrices(vector<int> &prices) {
    int n = prices.size();
    vector<int> ans(n);
    stack<int> stk;
    for (int i = n - 1; i >= 0; --i) {
      while (!stk.empty() && prices[stk.top()] > prices[i]) {
        stk.pop();
      }
      ans[i] = prices[i] - (stk.empty() ? 0 : prices[stk.top()]);
      stk.push(i);
    }
    return ans;
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  return 0;
}
