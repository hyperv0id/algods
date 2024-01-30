#include <bits/stdc++.h>
#include <string>

using namespace std;

// 2269. 找到一个数字的 K 美丽值
// https://leetcode.cn/problems/find-the-k-beauty-of-a-number/
// https://leetcode.cn/problems/find-the-k-beauty-of-a-number/submissions/499317449
class Solution {
  public:
    int divisorSubstrings(int num, int k) {
        int mod = pow(10, k - 1);
        string s = to_string(num);
        int now = 0;
        for (int i = 0; i < k; ++i) {
            now *= 10;
            now += s[i] - '0';
        }
        int cnt = now != 0 && now % num == 0;
        for (int i = k; i < s.size(); ++i) {
            now %= mod;
            now *= 10;
            now += s[i] - '0';
            if (now != 0 && now % num == 0) {
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
