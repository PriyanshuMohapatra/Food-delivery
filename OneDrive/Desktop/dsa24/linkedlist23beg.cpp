
#include <iostream>
using namespace std;
struct node{
    node *next;
    int data;
};
node *head=nullptr;
node *temp=nullptr;
void create(int n){
    node *nod=new node;
    
    nod->next=nullptr;
    nod->data=n;
    if(head==nullptr){
        head=temp=nod;
    }
    else{
        temp->next=nod;
        temp=nod;
    }
}
void insertbeg(int n){
    if(head==nullptr){
        create(n);
    }
    else{
        node *Node=new node;
        Node->next=head;
        Node->data=n;
        head=Node;
    }
}
int count(){
    
    if(head==nullptr)
    return 0;
    node *temp=head;
    int c=0;
    while(temp!=nullptr){
        temp=temp->next;
        c++;
    }
    return c;
}
void posin(int pos,int data){
    node *node1=new node;
    node1->data=data;
    temp=head;
    int c=count();
    if (pos < 1 || pos > c + 1) {
        cout << "Invalid position!" << endl;
        delete node1;
        return;
    }
    if(pos==1){
        insertbeg(data);
        return;
    }
    else{
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        node1->next=temp->next;
        temp->next=node1;
    }
    }
void deletefrompos(int n){

    node* temp=head;
    node* prev=NULL;
    if(n==1){
        head=head->next;
        delete temp;
        return;
    }
    
    for(int i=1;i<n;i++){
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    delete temp;
    }
    void endposdel(int n){

    node* temp=head;
    node* prev=NULL;
    int a=count();
    if(n==a){
        head=head->next;
        delete temp;
        return;
    }
    
    for(int i=1;i<=a-n;i++){
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    delete temp;
    }
void insertend(int dat){
    
    node *n=new node;
    n->data=dat;
    if(head==nullptr){
        head=n;
    }
    else{
    temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=n;
    n->next=NULL;
    }
}

void display(){
    temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void delbeg() {
    if (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}
void delend(){
    temp=head;
    node *prev=nullptr;
    while(temp->next!=nullptr){
        prev=temp;
        temp=temp->next;
    }
    if(prev==nullptr){
        delete temp;
        head=nullptr;
    }
    else{
        prev->next=nullptr;
        delete temp;
    }
}
int main(){
    int n;
    cin>>n;
    while(n>0){
        int dat;
        cin>>dat;
        create(dat);
        n--;
    }
    // int dat2;

    // cin>>dat2;

    // insertbeg(dat2);

    // int dat3;
    // cin>>dat3;
    // insertend(dat3);

    // delbeg();
    // delend();
    cout<<count();
    // int delpos;
    // cin>>delpos;
    // // deletefrompos(delpos);
    // endposdel(delpos);
    
    display();
}