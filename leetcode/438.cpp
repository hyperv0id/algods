#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findAnagrams(string s, string p) {
        if (s.length() < p.length()) {
            return {};
        };
        string sc = string(26, 0);
        string pc = string(26, 0);
        for (int i = 0; i < p.length(); i++) {
            pc[p[i] - 'a']++;
            sc[s[i] - 'a']++;
        }
        vector<int> ans;
        if (sc == pc) {
            ans.push_back(0);
        }
        for (int i = 0, j = p.length(); j < s.length(); i++, j++) {
            sc[s[i] - 'a']--;
            sc[s[j] - 'a']++;
            if (sc == pc) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
