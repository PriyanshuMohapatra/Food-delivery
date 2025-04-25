#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int arr[] = {1, 2, 3, 4, 5}; 
    int delIndex = 2; 

    for (int i = delIndex; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--; 

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
