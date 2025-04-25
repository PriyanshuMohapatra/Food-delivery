
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, sec;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin>>sec;

    for(int c = 0; c < sec; c++) {
        sort(arr, arr + n);
        arr[n - 1] = sqrt(arr[n - 1]);
    }

    long long sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    cout << sum;
    return 0;
}