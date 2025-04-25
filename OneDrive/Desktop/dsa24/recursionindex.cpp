#include <iostream>
#include <vector>
using namespace std;
void findIndex(int arr[], int target, vector<int> &vec, int i);
int main(){
    int arr[]={1,21,4,23,4,12,4};
    int target=4;
    vector<int> vec;
    int i=0;
    findIndex(arr,target,vec,i);
    for(int c:vec)
    cout<<c<<" ";
}
void findIndex(int arr[],int target,vector<int> &vec,int i){
    if(i==7)
    return;
    if(arr[i]==target)
    vec.push_back(i);
    findIndex(arr,target,vec,i+1);
}