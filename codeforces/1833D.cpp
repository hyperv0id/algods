#include <algorithm>
#include <array>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int t,n, l, r;
vector<int> a;

// 双指针
// https://codeforces.com/contest/1833/submission/207098831
void solve(){
    // 确定右端点，由于必须要翻转一次，所以从1开始比较
    int max_right = 1;
    for(int i=2;i<n;i++){
        if(a[i] > a[max_right]){max_right = i;}
    }
    if(max_right != n-1) {
        for(int i=max_right; i<n;i++){cout<< a[i]<<" ";}
        r = max_right - 1; // 最大值不是最后一个
    } else{
        r = n-1; // 最大值是最后一个
    }
    // if(max_right == 0){return;} // 最大值在最左边
    l = r - 1;
    while (l >= 0 && a[l] > a[0])
        l--;
    for (int i = r; i > l; i--)
        printf("%d ", a[i]);
    // for(int i=max_right-1; i>r; i--){printf("%d ", a[i]);}
    for (int i = 0; i <= l; i++)
        printf("%d ", a[i]);
}

int main (int argc, char *argv[]) {
    cin>>t;
    while(t--){
        cin>>n;
        a = vector<int>(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        solve();
        cout<< endl;
    }
    return 0;
}
