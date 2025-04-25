#include <iostream>
using namespace std;

int main(){
    int arr[]={1,2,3};
    int sum=0;
    int n=3;
    for(int i=0;i<n;i++){
        sum+=(n-i)*(i+1)*arr[i];
    }
    cout<<sum;
}