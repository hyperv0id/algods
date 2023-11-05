#include <bits/stdc++.h>
using namespace std;
// 11. 盛最多水的容器
/** 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i,
 0) 和 (i, height[i]) 。 找出其中的两条线，使得它们与 x
 轴共同构成的容器可以容纳最多的水。 返回容器可以储存的最大水量。
 说明：你不能倾斜容器。
 */
// https://leetcode.cn/problems/container-with-most-water/submissions/479916732
class Solution {
  public:
    int maxArea(vector<int> &height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            int small = min(height[l], height[r]);
            ans = max(ans, (r - l) * small); // 计算这两块板子之间能装多少水
            // 更新状态，使得每次能装的水都大于此次
            // BUT WHY?
            // 如果最大值在 [l,r] 里面，那么每次移动都不会导致最大值丢失
            while (height[l] <= small && l < r) {
                l++;
            }
            while (height[r] <= small && l < r) {
                r--;
            }
        }
        return ans;
    }
};
