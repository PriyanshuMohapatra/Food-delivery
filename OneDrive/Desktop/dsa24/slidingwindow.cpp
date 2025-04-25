#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    
    int arr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20,10,11,12};
    int k = 4;
    int sum=0;
    int l=0;
    int r=k-1;
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    int maxs=sum;
    for(int i=k;i<12;i++){
        int sum=sum-arr[i-k]+arr[i];
        maxs=max(maxs,newsum);
    }

    cout<<maxs;

    return 0;
}