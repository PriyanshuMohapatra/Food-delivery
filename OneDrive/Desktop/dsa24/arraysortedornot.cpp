#include <iostream>
using namespace std;

bool sorted(int arr[],int i){
    if(i==4){
        return true;
    }
    return arr[i]<arr[i+1] && sorted(arr,i+1);
}
int main(){
    int arr[]={1,2,3,41,31};
    cout<<sorted(arr,0);
}
