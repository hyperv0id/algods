// 翻转数组
#include <bits/stdc++.h>
using namespace std;

void reverse_array(int *arr, int n) {
    for (int i = 0; i < n / 2; i++) {
        arr[i] ^= arr[n - i - 1];
        arr[n - i - 1] ^= arr[i];
        arr[i] ^= arr[n - i - 1];
    }
}

int main(int argc, char *argv[]) {

    {
        int arr[] = {1, 2, 3, 4, 5};
        reverse_array(arr, 5);
        for (int i = 0; i < 5; i++) {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }
    {
        int arr[] = {3, 2, 3, 4, 5};
        reverse_array(arr, 5);
        for (int i = 0; i < 5; i++) {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }

    return 0;
}
