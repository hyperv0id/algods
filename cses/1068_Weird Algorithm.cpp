#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<uint64_t> tab;
    uint64_t n;
    cin >> n;
    while (n != 1 && !tab.count(n))
    {
        tab.insert(n);
        cout << n << " ";
        n = n & 1 ? 3 * n + 1 : n >> 1;
    }
    cout << 1;
    // for(auto n: tab){
    // cout << n <<" ";
    // }cout << endl;
    return 0;
}