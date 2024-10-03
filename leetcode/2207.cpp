#include <algorithm>
#include <bits/stdc++.h>

// 2207. 字符串中最多数目的子序列
// https://leetcode.cn/problems/maximize-number-of-subsequences-in-a-string/submissions/567526098
using namespace std;
class Solution {
public:
  long long maximumSubsequenceCount(string text, string pattern) {
    if (pattern[0] == pattern[1]) {
      long long ans = 0;
      long long cnt = 0;
      for (char c : text) {
        cnt += c == pattern[0];
      }
      ans += cnt * (cnt + 1) / 2;
      return ans;
    }
    long long ans = 0;
    int cnt = 0, c1 = 0, c2 = 0;
    for (char c : text) {
      if (c == pattern[0])
        cnt++;
      if (c == pattern[1])
        ans += cnt;

      c1 += c == pattern[0];
      c2 += c == pattern[1];
    }
    return ans + max(c1, c2);
  }
};
