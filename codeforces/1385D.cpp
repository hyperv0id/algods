#include <bits/stdc++.h>
#include <string_view>
using namespace std;
// D. a-Good String
int dist(string_view &v1, string_view &v2) {
    int cnt = 0, len = min(v1.size(), v2.size());
    for (int i = 0; i < len; ++i) {
        if (v1[i] != v2[i])
            cnt++;
    }
    return cnt;
}
// https://codeforces.com/problemset/submission/1385/250313810
int dist(string_view &s, char c) {
    int len = s.size();
    if (s.size() == 1) {
        return s[0] == c ? 0 : 1;
    }
    // comp dist l and dist r
    string half(s.size() / 2, c);
    string_view hv(half);
    string_view l(s.data(), len / 2);
    string_view r(s.data() + len / 2, len / 2);
    return min(dist(l, hv) + dist(r, c + 1), dist(l, c + 1) + dist(hv, r));
}

int main(int argc, char *argv[]) {
    int tc;
    cin >> tc;
    while (tc--) {

        int n;
        cin >> n;
        string s;
        cin >> s;
        string_view view(s);
        cout << dist(view, 'a') << endl;
    }
    return 0;
}
