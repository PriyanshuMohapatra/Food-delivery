#include <iostream>
#include <algorithm>
using namespace std;
// void fun(int arr[],int i){
//     int s=4;
//     if(i>=5/2)
//     return;
//     swap(arr[i],arr[4-i]);
//     return fun(arr,i+1); 
// }
int fibonacci(int n){
    if(n<=1)
    return n;
    
    return fibonacci(n-1)+fibonacci(n-2);
}
int main(){
    // int arr[]={1,2,3,4,5};
    // fun(arr,0);
    // for(int i=0;i<5;i++)
    // cout<<arr[i];
    int n=4;
    int a=fibonacci(4);
    cout<<a;

}