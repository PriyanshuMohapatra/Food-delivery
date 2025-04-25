#include <iostream>
using namespace std;

struct node {
    node* next;
    int data;
};

node* head = nullptr;
node* temp = nullptr;

void create(int data) {
    node* node1 = new node;
    node1->next = nullptr;
    node1->data = data;
    if (head == nullptr) {
        head = temp = node1;
    } else {
        temp->next = node1;
        temp = node1;
    }
}

int count() {
    int c = 0;
    if (head == nullptr) {
        cout << "No nodes" << endl;
        return 0;
    }
    temp = head;
    while (temp != nullptr) {
        c++;
        temp = temp->next;
    }
    return c;
}

void sort() {
    int c = count();
    
    for (int i = 0; i < c - 1; ++i) {
         temp=head;
        for (int j = 0; j < c - i - 1; ++j) {
            if (temp->data > temp->next->data) {
                swap(temp->data, temp->next->data);
            }
            temp = temp->next;
        }
    }
}
void reverse()
{
    temp=head;
    node *prev=nullptr;
    node *front=nullptr;
    while(temp!=nullptr){
        front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    head=prev;
}
void display() {
    if (head == nullptr) {
        cout << "No nodes to display" << endl;
        return;
    }
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter data for each node:" << endl;
    while (n > 0) {
        int data;
        cin >> data;
        create(data);
        n--;
    }
    sort();
    cout << "Sorted list: ";
    display();
    cout<<"reversed list: ";
    reverse();
    display();

    return 0;
}
