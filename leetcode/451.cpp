#include <bits/stdc++.h>

using namespace std;

// 给定一个字符串 s ，根据字符出现的 频率 对其进行 降序排序 。一个字符出现的
// 频率 是它出现在字符串中的次数。
// 返回 已排序的字符串 。如果有多个答案，返回其中任何一个。
// https://leetcode.cn/problems/sort-characters-by-frequency/submissions/468592952/
class Solution {
  public:
    string frequencySort(string s) {
        int cnt[256] = {0};
        for (char c : s) {
            cnt[c]++;
        }
        sort(s.begin(), s.end(), [&cnt](char x, char y) {
            if (cnt[x] == cnt[y]) {
                return x < y;
            }
            return cnt[x] >= cnt[y];
        });
        return s;
    }
};
int main(int argc, char *argv[]) {
    Solution s;
    string str;
    cin >> str;
    cout << s.frequencySort(str);
    return 0;
}
