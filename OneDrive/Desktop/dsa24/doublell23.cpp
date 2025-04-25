#include <iostream>
using namespace std;
struct  node
{
    /* data */
    int data;
    node *prev;
    node *next;
};
node *head=NULL;
node *tail=nullptr;
void create(int data) {
    node *node1 = new node;
    node1->data = data;
    node1->next = nullptr;

    if (head == nullptr) {
        head = tail = node1;
        node1->prev = nullptr;
    } else {
        tail->next = node1;
        node1->prev = tail;
        tail=node1;
    }
}
void insertbeg(int data){
    node *nod=new node;
    
    
    nod->data=data;
    nod->prev=nullptr;
    if(head==nullptr){
        head=tail=nod;
        nod->next=nullptr;
    }
    else{
        nod->next=head;
        head->prev=nod;
        head=nod;
    }
}
void insertend(int data){
    node *node1=new node;
    node1->data=data;
    node1->next=nullptr;
    node1->prev=nullptr;
    if(head==nullptr){
        head=tail=node1;
    }
    else{
        tail->next=node1;
        node1->prev=tail;
        tail=node1;
    }
}
void insertatanypos(int data,int pos){
    if(pos==1){
        insertbeg(data);
        return;
    }
    node *ode=new node;
    ode->data=data;
    ode->next=nullptr;
    ode->prev=nullptr;
    node *temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    if (temp == nullptr) {
        cout << "Position out of bounds" << endl;
        delete ode; 
        return;
    }
    ode->next=temp->next;
    temp->next=ode;
    ode->prev=temp;



}
void delbeg(){
    if(head==nullptr){
        cout<<"No elements to del";
        return;
    }
    node *temp=head;
    head=head->next;
    delete temp;
    head->prev=nullptr;

}
void delend()
{
    if(head==nullptr){
        return;
    }
    else if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }
    node *temp=tail;
    tail->prev->next=nullptr;
    tail=tail->prev;
    delete temp;
}
void delpos(int pos){
    if(head==nullptr){
        cout<<"No nodes to delete";
        return;
    }
    if(pos==1){
        delbeg();
        return;
    }
    node *temp=head;
    for(int i=1;i<=pos-1;i++){
        temp=temp->next;
    }
    temp->prev->next=temp->next;
    delete temp;
    

}
void display(){
    if(head==nullptr){
        cout<<"No nodes";
        return;
    }
    else{
        node *temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
}
int main(){
    int n;
    cout<<"Enter no of nodes: ";
    cin>>n;
    cout<<"enter data: ";
    while(n>0){
        int data;
        cin>>data;
        create(data);
        n--;
    }
    int data1;
    cout<<"enter the element to insert at beg: ";
    cin>>data1;
    insertbeg(data1);
    cout<<"Enter element to insert at end: ";
    int data2;
    cin>>data2;
    insertend(data2);
    cout<<"enter DATA nd position to enter the data :";
    int data3,pos;
    cin>>data3>>pos;
    insertatanypos(data3,pos);
    delbeg();
    delend();
    cout<<"enter pos to del: ";
    int posd;
    cin>>posd;
    delpos(posd);
    display();

}