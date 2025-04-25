#include <iostream>
using namespace std;
int rev(int n);
int main(){
    int a=rev(1342);
    cout<<a;
}
int rev(int n){
    if(n==0)
    return 0;

    return (n%10)*10 + rev(n/10);
}