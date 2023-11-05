#include <bits/stdc++.h>
using namespace std;

/*  42. 接雨水
    给定 n 个非负整数表示每个宽度为 1
    的柱子的高度图，计算按此排列的�子，下雨之后能接多少雨水。
*/
// https://leetcode.cn/problems/trapping-rain-water/submissions/379524910
class Solution {
  public:
    int trap(vector<int> &height) {
        int ans = 0;
        int n = height.size();

        // 计算所有 黑块块的和
        int sum_block = accumulate(height.begin(), height.end(), 0);

        int left_max, right_max, max_v;
        left_max = right_max = max_v = 0;

        for (int i = 0, j = n - 1; i < n; i++, j--) {
            max_v = max(max_v, height[i]);
            if (left_max < height[i]) {
                // left_max.push(make_pair(height[i], i));
                ans -= (height[i] - left_max) * i;
                left_max = height[i];
            }
            if (right_max < height[j]) {
                // right_max.push(make_pair(height[j], n-j-1));
                ans -= (height[j] - right_max) * (n - j - 1);
                right_max = height[j];
            }
        }

        ans += (long)max_v * n;
        ans -= sum_block;
        return ans;
    }
};
