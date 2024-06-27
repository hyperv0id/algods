#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-100-liked
// 字母异位词分组
// https://leetcode.cn/problems/group-anagrams/submissions/542483663?envType=study-plan-v2&envId=top-100-liked
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> table;
    for (auto &&s : strs) {
        auto cp = s;
        sort(cp.begin(), cp.end());
        table[cp].push_back(s);
    }
    vector<vector<string>> ans;
    for(auto &&[k,v]:table){
      ans.push_back(v);
    }
    return ans;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  return 0;
}
