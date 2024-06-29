#include <bits/stdc++.h>

using namespace std;


// https://leetcode.cn/problems/remove-trailing-zeros-from-a-string/submissions/542722865?envType=daily-question&envId=2024-06-29
// 2710: 移除字符串中的尾随零
class Solution {
public:
    string removeTrailingZeros(string num) {
        int cnt =0;
        for(auto it=num.rbegin(); it != num.rend(); it++) {
            if(*it == '0')cnt++;
            else break;
        }
        return num.substr(0, num.size() - cnt);
    }
};

int main(int argc, char *argv[]) {
  Solution s;
  return 0;
}
