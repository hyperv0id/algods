#include <bits/stdc++.h>

using namespace std;

#define MAXSIZE 200010
int t, n, k;
int a[MAXSIZE], w[MAXSIZE];

// https://codeforces.com/contest/1369/submission/202583481
int main(int argc, char *argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < k; i++) {
            cin >> w[i];
        }
        // 排序
        sort(a, a + n);
        sort(w, w + k);
        long long ans = 0;
        for(int i=0;i<k;i++){
            ans += a[n-1-i];
            if(w[i] == 1){
                ans += a[n-1-i];
            }
        }
        int j = 0;
        while(k--){
            if(w[k] == 1){break;}
            ans += a[j];
            j += w[k] - 1; 
        }

        cout << ans << endl;
    }
    return 0;
}
