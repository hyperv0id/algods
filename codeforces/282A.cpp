
#include<bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/submission/282/203224908
int main(){
    int n, ans = 0;cin>>n;
    string s;
    while(n--){
        cin>>s;
        if(s.substr(0,2) == "++" || s.substr(1,2) == "++"){
            ans++;
        }else{
            ans--;
        }
    }
    cout << ans;
    return 0;
}