// 删除所有值在 s-t之间的数字, **数组无序**

#include <bits/stdc++.h>
using namespace std;

// 同04.cpp
int remove_x(int *arr, int n, int s, int t) {
    int cnt = 0;
    for (int i = 0, j = 0; j < n; j++) {
        if (arr[j] < s || arr[j] > t) {
            cnt++;
            arr[i++] = arr[j];
        }
    }
    return cnt;
}

int main(int argc, char *argv[]) {

    {
        int arr[] = {1, 2, 3, 4, 5};
        cout << remove_x(arr, 5, 1, 2) << endl;
        for (int i = 0; i < 5; i++) {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }
    {
        int arr[] = {3, 2, 3, 4, 5};
        cout << remove_x(arr, 5, 3, 4) << endl;
        for (int i = 0; i < 5; i++) {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }

    return 0;
}
