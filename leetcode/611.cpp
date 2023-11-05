#include <bits/stdc++.h>
using namespace std;

// 611. 有效三角形的个数
// 给定一个包含非负整数的数组 nums ，返回其中可以组成三角形三条边的三元组个数。
// https://leetcode.cn/problems/valid-triangle-number/submissions/479915044/
class Solution {
  public:
    int triangleNumber(vector<int> &nums) {
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // 二分查找
                int left = j + 1, right = n - 1, k = j, mid;
                while (left <= right) {
                    mid = left + right >> 1;
                    if (nums[mid] < nums[i] + nums[j]) {
                        k = mid;
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                ans += k - j; // 有多少个 k
            }
        }
        return ans;
    }
};
