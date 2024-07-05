// https://leetcode.cn/problems/majority-element/?envType=study-plan-v2&envId=top-interview-150
// 169. 多数元素
// 给定一个大小为 n 的数组 nums
// ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
// 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/majority-element/submissions/544177007?envType=study-plan-v2&envId=top-100-liked
int majorityElement(int *nums, int numsSize) {
    int ans = INT_MAX, cnt = 0;
    for (int i = 0; i < numsSize; i++) {
        if (ans != nums[i]) {
            cnt--;
        } else {
            cnt++;
        }
        if (cnt < 0) {
            ans = nums[i];
            cnt = 1;
        }
    }
    return ans;
}
