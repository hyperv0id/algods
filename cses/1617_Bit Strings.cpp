#include<bits/stdc++.h>
using namespace std;

#define MOD size_t(1e9+7)


// https://cses.fi/problemset/result/5945310/
size_t calc(int n){
    // cout << n<<" ";
    if(n<30){
        return 1<<n % MOD;
    }
    int a = n>>1, b = (n+1)>>1;
    return (calc(a) * calc(b)) % MOD;
}
int main(){
    int n;cin>>n;
    cout << calc(n);
    return 0;
}