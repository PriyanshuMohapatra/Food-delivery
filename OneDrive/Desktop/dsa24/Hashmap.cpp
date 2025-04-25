#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;
void frequency(int arr[], int n, map<int, int>& m) {
    for (int i = 0; i < n; ++i) {
        m[arr[i]]++; 
    }
    for (auto i : m) {
        cout << i.first << " " << i.second << endl;
    }
}
int main() {
    map<int,int> m; 
    int arr[] = {1, 2, 3, 2, 1, 3, 4, 12, 3, 1};
    int n = 10;
    frequency(arr, n, m);
    return 0;
}

