#include <iostream>
#include <vector>
using namespace std;
int main(){
    int arr[]={1,3,4,6};
    vector<int> a;
    for(int i=0;i<4;i++){
        int count=0;
        for(int j=0;j<4;j++){
            if(i!=j){
                if(arr[j]%arr[i]==0)
                count++;
            }
        }
        a.push_back(count);
    }
    for(int i=0;i<4;i++){
        cout<<a[i]<<" ";
    }
}