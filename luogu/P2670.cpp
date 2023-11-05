#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define MAX_SIZE 100005
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
// types
typedef long long ll;
typedef unsigned long long ull;

// https://www.luogu.com.cn/record/133409071
int m, n;
char arr[101][101];

void count(int x, int y) {
    char cnt = '0';
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            int nx = x + i, ny = y + j;
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                continue;
            }
            if (arr[nx][ny] == '*') {
                cnt++;
            }
        }
    }
    arr[x][y] = cnt;
}

int main(int argc, char *argv[]) {
    int tc = 1;
    // cin>>tc;
    while (tc--) {
        cin >> m >> n;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (arr[i][j] != '*') {
                    count(i, j);
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << arr[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
