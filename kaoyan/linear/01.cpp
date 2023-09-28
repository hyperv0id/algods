// 删除最小的元素，由最后一个元素替代

#include <bits/stdc++.h>
using namespace std;

int reverse_array(int *arr, int n) {
    int min_pos = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < arr[min_pos]) {
            min_pos = i;
        }
    }
    int ans = arr[min_pos];
    arr[min_pos] = arr[n - 1];
    return ans;
}

int main(int argc, char *argv[]) {

    {
        int arr[] = {1, 2, 3, 4, 5};
        cout << reverse_array(arr, 5) << endl;
        for (int i = 0; i < 5; i++) {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }
    {
        int arr[] = {3, 2, 3, 4, 5};
        cout << reverse_array(arr, 5) << endl;
        for (int i = 0; i < 5; i++) {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }

    return 0;
}
