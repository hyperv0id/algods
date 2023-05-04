#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a;
    cin>>n;
    int ans = 0;
    for(int i=1;i<n;i++){
        cin >> a;
        ans ^= a^i;
    }
    ans ^= n;
    cout << ans;
    return 0;
}