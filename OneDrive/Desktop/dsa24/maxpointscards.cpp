#include <iostream>
#include <algorithm>
//max points you can obtain from k  cards
//out of n diff cards 
//you need to pickup from the bacck or front
using namespace std;
int main(){
    int arr[]={6,2,3,4,7,2,7,1};
    int lsum=0;
    int rsum=0;
    int maxsum=0;
    int k=4;
    for(int i=0;i<k;i++){
        lsum+=arr[i];
    }
    maxsum=lsum;
    int r=7;
    for(int i=k-1;i>=0;i--){
        lsum-=arr[i];
        rsum+=arr[r];
        maxsum=max(maxsum,lsum+rsum);
        r--;
    }
    cout<<maxsum;
}