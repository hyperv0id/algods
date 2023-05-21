#include <bits/stdc++.h>

using namespace std;

// https://codeforces.com/contest/1822/submission/204533712
int main(int argc, char *argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        if(n == 1){cout<<1<<endl;continue;}
        if(n&1){
            cout << -1<< endl;
            continue;
        }
        for(int i=0;i<n;i++){
            if(i&1){
                cout << i;
            }else{
                cout << n-i;
            }
            cout << " ";
        }cout<< endl;
    }
    return 0;
}
