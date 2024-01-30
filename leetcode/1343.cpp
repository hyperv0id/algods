#include <bits/stdc++.h>

using namespace std;

// 1343. 大小为 K 且平均值大于等于阈值的子数组数目
// https://leetcode.cn/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/
// https://leetcode.cn/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/submissions/499332712
class Solution {
  public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold) {
        threshold *= k;
        int val = 0, cnt = 0;
        for (int i = 0; i < k; ++i) {
            val += arr[i];
        }
        if (val >= threshold) {
            cnt++;
        }
        for (int i = k; i < arr.size(); ++i) {
            val += arr[i];
            val -= arr[i - k];
            if (val >= threshold) {
                cnt++;
            }
        }
        return cnt;
    }
};
int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
