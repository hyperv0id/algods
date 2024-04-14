#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        string c1(26, 0), c2(26, 0);
        for (char c : s1)
            c1[c - 'a']++;
        int i = 0;
        for (i = 0; i < s1.size(); ++i) {
            c2[s2[i] - 'a']++;
        }
        if (c1 == c2)
            return true;
        for (int j = 0; i < s2.size(); ++j, ++i) {
            c2[s2[i] - 'a']++;
            c2[s2[j] - 'a']--;
            if (c1 == c2)
                return true;
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
