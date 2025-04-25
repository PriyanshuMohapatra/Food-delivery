#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    
    sort(arr, arr + n);
    
    int totalCost = 0;
    
    
    for (int i = 0; i < n - 1; i++) {
        
        int mergeCost = arr[i] + arr[i + 1];
        
       
        totalCost += mergeCost;
        
        
        arr[i + 1] = mergeCost;
        
        
        sort(arr, arr + n );  
    }
    
    cout << totalCost << endl;
    return 0;
}