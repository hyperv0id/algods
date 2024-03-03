#include <bits/stdc++.h>
using namespace std;

// 删除所有值为x的数字
int remove_x(int *arr, int n, int x) {
    int cnt = 0;
    for (int i = 0, j = 0; j < n; j++) {
        if (arr[j] != x) {
            cnt++;
            arr[i++] = arr[j];
        }
    }
    return cnt;
}

int main(int argc, char *argv[]) {

    {
        int arr[] = {1, 2, 3, 4, 5};
        cout << remove_x(arr, 5, 1) << endl;
        for (int i = 0; i < 5; i++) {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }
    {
        int arr[] = {3, 2, 3, 4, 5};
        cout << remove_x(arr, 5, 3) << endl;
        for (int i = 0; i < 5; i++) {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }

    return 0;
}
