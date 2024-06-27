#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/lexicographically-smallest-string-after-substring-operation/submissions/542480483
class Solution {
public:
    string smallestString(string a) {
        if(a == string(a.size(), 'a')) {
            a[a.size()-1] = 'z';
            return a;
        }
        int i=0;
        for(;i<a.size();i++){
            if(a[i] != 'a'){break;}
        }
        // 减少直到为a
        for(;i<a.size();i++){
            if(a[i] == 'a'){break;}
            a[i]--;
        }
        return a;
    }
};

int main(int argc, char *argv[]) {
  Solution s;
  return 0;
}
