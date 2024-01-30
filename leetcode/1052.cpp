#include <bits/stdc++.h>

using namespace std;

// 1052. 爱生气的书店老板
// https://leetcode.cn/problems/grumpy-bookstore-owner/description/
//
class Solution {
  public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes) {
        int satis = 0, length = customers.size();
        // 什么都不做的满意人数
        for (int i = 0; i < length; ++i) {
            satis += (1 - grumpy[i]) * customers[i];
        }
        // 抑制前minutes
        for (int i = 0; i < minutes; ++i) {
            if (grumpy[i])
                satis += customers[i];
        }
        int ans = satis;
        for (int i = minutes; i < length; ++i) {
            if (grumpy[i])
                satis += customers[i];
            if (grumpy[i - minutes])
                satis -= customers[i - minutes];
            ans = max(ans, satis);
        }
        return ans;
    }
};
int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
