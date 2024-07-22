#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
// https://leetcode.cn/problems/find-if-array-can-be-sorted/submissions/546306610
// 3011. 判断一个数组是否可以变为有序
class Solution {
public:
  bool canSortArray(vector<int> &nums) {
    int n = nums.size();
    int lastCnt = 0;
    int lastGroupMax = 0;
    int curGroupMax = 0;

    for (int i = 0; i < n; i++) {
        int num = nums[i];
        int curCnt = __builtin_popcount(num);
        if (curCnt == lastCnt) {
            curGroupMax = max(curGroupMax, num);
        } else {
            lastCnt = curCnt;
            lastGroupMax = curGroupMax;
            curGroupMax = num;
        }
        if (num < lastGroupMax) {
            return false;
        }
    }
    return true;
  }
};

