#include <bits/stdc++.h>

using namespace std;

class Solution {
    // TODO
  public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            cerr << "SIZE";
            return false;
        }
        cout << s1 + " " << s2 << " " << s3 << endl;
        if (s1.size() == 1 && s2.size() == 0) {
            return s1 == s3;
        }
        if (s2.size() == 1 && s1.size() == 0) {
            return s2 == s3;
        }
        bool r1 = false, r2 = false;
        if (s1.size() > 0 && s1[0] == s3[0]) {
            r1 = isInterleave(s1.substr(1, s1.size() - 1), s2,
                              s3.substr(1, s3.size() - 1));
        }
        if (s2.size() > 0 && s2[0] == s3[0]) {
            r2 = isInterleave(s2.substr(1, s2.size() - 1), s1,
                              s3.substr(1, s3.size() - 1));
        }
        return r1 || r2;
    }
};
int main(int argc, char *argv[]) {
    Solution s;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    cout << s.isInterleave(s1, s2, s3);
    return 0;
}
