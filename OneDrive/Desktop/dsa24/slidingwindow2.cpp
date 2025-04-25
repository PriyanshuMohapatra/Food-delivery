#include <iostream>
#include <algorithm>
using namespace std;

//longest subarray with sum <=k 
int main(){
    int arr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20,10,11,12};
    int n=12;
    int l=0;
    int r=0;
    int maxlen=0;
    int sum=0;
    int tar=13;
    while(r<n){
        sum+=arr[r];
        if(sum>tar){
            sum=sum-arr[l];
            l=l+1;
        }
        if(sum<=tar){
            maxlen=max(maxlen,r-l+1);
        }
        r++;
    }
    cout<<maxlen; 
}