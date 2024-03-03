#include <bits/stdc++.h>
using namespace std;

// 删除重复元素，数组有序

int remove_dupl(int *arr, int n) {
    int i = 0, j = 1;
    while (j < n) {
        if (arr[j] != arr[j - 1]) {
            arr[++i] = arr[j];
        }
        j++;
    }
    return i + 1;
}

void print_arr(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main(int argc, char *argv[]) {

    {
        int arr[] = {1, 2, 3, 4, 5};
        print_arr(arr, remove_dupl(arr, 5));
    }
    {
        int arr[] = {3, 3, 3, 4, 5};
        print_arr(arr, remove_dupl(arr, 5));
    }

    return 0;
}
