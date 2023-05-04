#include<bits/stdc++.h>
using namespace std;
//https://cses.fi/problemset/result/5945249/
int main(){
    long long n;cin>>n;
    long long pre, now, ans = 0;
    n -= 1;
    cin >> pre;
    while (n--)
    {
        cin >> now;
        if (now < pre){
            ans += pre - now;
        }
        else{
            pre = now;
        }
    }
    cout << ans;

    return 0;
}