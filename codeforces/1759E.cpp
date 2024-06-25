#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// https://codeforces.com/problemset/submission/1759/267210157
int solve(ll num, vector<int> &arr, int mul[3])
{
    int idx = 0, cnt = 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        while (num <= arr[i])
        {
            if (idx == 3)
                return i;
            num *= mul[idx++];
        }
        num += arr[i] / 2;
    }
    return arr.size();
}
int mul[][3] = {{2, 2, 3}, {2, 3, 2}, {3, 2, 2}};

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, num;
        cin >> n >> num;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int val = -1;
        for (int j = 0; j < 3; j++)
            val = max(val, solve(num, arr, mul[j]));
        cout << val << endl;
    }
    return 0;
}
