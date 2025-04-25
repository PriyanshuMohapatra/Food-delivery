#include <iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
node *top=nullptr;
void push(int x){
    node *node1=new node;
    node1->data=x;
    node1->next=top;
    top=node1;

}
void pop(){
    node *temp=top;
    if(top==nullptr){
        cout<<"Empty stack";
        return;
    }
    cout<<temp->data<<" ";
    top=top->next;
    delete temp;
}
void display(){
    node *temp=top;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    cout<<"Enter no of elements: ";
    int n;
    cin>>n;
    cout<<"Enter elements: ";
    while(n>0){
        int x;
        cin>>x;
        push(x);
        n--;
    }
    display();
    cout<<endl;
    cout<<"Pop operation is called: ";

    pop();
    cout<<endl; 
    cout<<"After deletion: ";
    display();
}