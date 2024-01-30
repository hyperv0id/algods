#include <bits/stdc++.h>

using namespace std;

// 1456. 定长子串中元音的最大数目
// https://leetcode.cn/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/
// https://leetcode.cn/problems/maximum-number-of-vowels-in-a-substring-of-given-length/submissions/499316217
class Solution {
  public:
    int maxVowels(string s, int k) {
        int cnt = 0;
        for (int i = 0; i < k; ++i) {
            if (isVowel(s[i])) {
                cnt++;
            }
        }
        int ans = cnt;
        for (int i = k; i < s.size(); ++i) {
            if (isVowel(s[i])) {
                cnt++;
            }
            if (isVowel(s[i - k])) {
                cnt--;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
