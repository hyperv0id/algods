#include <bits/stdc++.h>
#include <cstddef>
using namespace std;


// https://leetcode.cn/problems/longest-substring-without-repeating-characters/submissions/386360240/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int left=0,right=0;
        vector<bool> has(120, false);
        while(right < s.size()){
            char c = s[right];
            // 元素存在
            while(has[c]){
                // 将left对应字母的置为0,相当于窗口变短
                has[s[left++]] = false;;
            }
            ans = max(ans, right - left+1);
            has[s[right++]] = true;
        }

        return ans;
    }
};

int main (int argc, char *argv[]) {
    auto sol = Solution();
    string inp;
    cin >> inp;
    cout << sol.lengthOfLongestSubstring(inp);
    return 0;
}
