#include <iostream>
using namespace std;


int bin(int arr[],int low,int high,int x){
    if(high>=low){
        int mid=(high+low)/2;
    
    if(arr[mid]==x)
        return mid;
    
    if(arr[mid]>x){
        return bin(arr,low,mid-1,x);
    }
    return bin(arr,mid+1,high,x);    
    }
    return -1;
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    int high=size-1;
    cout<<"Element you wanna search: ";
    int x;
    cin>>x;
    int a=bin(arr,0,high,x);
    if(a==-1){
        cout<<"Element not present";
    }
    else{
        cout<<"Element "<<x<<" is present at "<<a;
    }

}