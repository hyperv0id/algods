#include <bits/stdc++.h>

using namespace std;
// 2414. 最长的字母序连续子字符串的长度
// https://leetcode.cn/problems/length-of-the-longest-alphabetical-continuous-substring/
class Solution {
public:
  int longestContinuousSubstring(string s) {
    int ans = 1, cnt = 1;
    for (int i = 0; i < s.size(); i++) {
      if (i >= 1 && s[i] == s[i - 1] + 1) {
        cnt++;
      } else {
        cnt = 1;
      }
      ans = max(ans, cnt);
    }
    return min((int)s.size(), ans);
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  return 0;
}
