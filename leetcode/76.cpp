#include <bits/stdc++.h>
#include <climits>

using namespace std;

// https://leetcode.cn/problems/minimum-window-substring/submissions/543309617?envType=study-plan-v2&envId=top-100-liked
// 76. 最小覆盖子串
class Solution {
public:
  vector<int> cnt;
  string minWindow(string s, string t) {
    cnt = vector<int>(128);
    auto ok = [&]() {
      for (int i = 0; i < 128; ++i)
        if (cnt[i] < 0)
          return false;
      return true;
    };
    for (char c : t)
      cnt[c]--;

    int len = INT_MAX;
    int pos = 0;
    for (int i = 0, j = 0; j < s.size(); ++j) {
      cnt[s[j]]++;
      if (ok()) {
        while (cnt[s[i]] > 0) {
          cnt[s[i++]]--;
        }
        if (j - i + 1 < len) {
          len = j - i + 1;
          pos = i;
        }
      }
    }

    return len == INT_MAX ? "" : s.substr(pos, len);
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.minWindow("cabwefgewcwaefgcf", "cae") << endl;
  cout << s.minWindow("THISISBANCBK", "ABC") << endl;
  cout << s.minWindow("a", "aa") << endl;
  cout << s.minWindow("a", "a") << endl;
  return 0;
}
