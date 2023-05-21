#include<bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/1828/submission/206690548
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        for (size_t i = 1; i <= n; i++)
        {
            cout << i*2 << " ";
        }cout << endl;
    }
    return 0;
}