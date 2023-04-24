
#include<bits/stdc++.h>
using namespace std;
//https://codeforces.com/problemset/submission/263/203225180
int main(){
    int a[5][5];
    int x, y;
    for(int i=0;i<25;++i){
        cin >> a[i/5][i%5];
        if(a[i/5][i%5]==1){
            x = i/5;
            y = i%5;
        }
    }
    cout << abs(x-2) + abs(y-2);

    return 0;
}