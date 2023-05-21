#include<bits/stdc++.h>

using namespace std;

int t,n;
int a[200005];

// https://codeforces.com/contest/1828/submission/206690978
int solve(int n, int* a){
    int ans = 0;
    for(int i=0;i<n;i++){
        a[i] = abs(i+1 - a[i]) % n;
        // if(a[i] == 0){a[i] = n;}
        if(a[i] != 0){
            ans = a[i];
        }
    }
    if(ans == 0){return n;}

    for(int i=0;i<n;i++){
        if(a[i] == 0){continue;}
        ans = __gcd(ans, a[i]);
        // cout << ans <<"-";
    }
    return ans;
}

int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout << solve(n,a) << endl;
    }
    return 0;
}