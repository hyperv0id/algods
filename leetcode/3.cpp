#include <bits/stdc++.h>
using namespace std;

/**
    3. 无重复字符的最长子串
    给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 */
// https://leetcode.cn/problems/longest-substring-without-repeating-characters/submissions/386360240
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int left = 0, right = 0;
        vector<bool> has(120, false);
        while (right < s.size()) {
            char c = s[right];
            // 元素存在
            while (has[c]) {
                // 将left对应字母的置为0,相当于窗口变短
                has[s[left++]] = false;
                ;
            }
            ans = max(ans, right - left + 1);
            has[s[right++]] = true;
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
