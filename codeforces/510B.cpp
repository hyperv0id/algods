#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define endl '\n'
#define MAX_SIZE 100005
#define MOD 1000000007
// types
typedef long long ll;
typedef unsigned long long ull;

int n, m;
char mat[51][51];
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

// https://codeforces.com/problemset/submission/510/250327652
bool dfs(int x, int y, char c, int lx = -1, int ly = -1) {
    if (mat[x][y] == c) {
        mat[x][y] -= 26;
    } else if (mat[x][y] == c - 26) {
        return 1;
    } else {
        return 0;
    }
    for (int i = 0; i < 4; ++i) {
        // calc next pos
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (nx == lx && ny == ly) {
                continue;
            }
            if (dfs(nx, ny, c, x, y))
                return 1;
        }
    }
    return 0;
}

bool foo() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] <= 'Z' && mat[i][j] >= 'A') {
                // not visited
                if (dfs(i, j, mat[i][j])) // found
                    return 1;
            }
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    int tc = 1;
    // cin>>tc;
    while (tc--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> mat[i][j];
            }
        }
        if (foo())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
