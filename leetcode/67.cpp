#include <bits/stdc++.h>
#include <string>

using namespace std;

class Solution {
  public:
    string addBinary(string a, string b) {
        string ans;
        int add = 0;
        for (auto ia = a.rbegin(), ib = b.rbegin();
             ia != a.rend() || ib != b.rend();) {
            char ch = add;
            if (ia != a.rend()) {
                ch += *ia - '0';
                ia++;
            }
            if (ib != b.rend()) {
                ch += *ib - '0';
                ib++;
            }
            add = ch >> 1;
            ch &= 1;
            ch += '0';
            cerr << string(1, ch);
            ans.push_back(ch);
        }
        if (add) {
            ans.push_back('1');
            cerr << 1 << endl;
        }

        return string(ans.rbegin(), ans.rend());
    }
};
int main(int argc, char *argv[]) {
    Solution s;
    string a, b;
    cin >> a >> b;
    cout << s.addBinary(a, b);
    return 0;
}
