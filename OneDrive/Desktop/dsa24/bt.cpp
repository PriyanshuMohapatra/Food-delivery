#include<iostream>
using namespace std;

struct node {
    node *left;
    node *right;
    int data;
};
node* create() {
    int x;
    cin >> x;
    if (x == -1) 
        return nullptr;
    
    node* node1 = new node; 
    node1->data = x;
    
    cout << "Enter left child of " << x << ": ";
    node1->left = create();  
    
    cout << "Enter right child of " << x << ": ";
    node1->right = create(); 
    
    return node1;
}


void preorder(node *root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";  
    preorder(root->left);       
    preorder(root->right);      
}
void inorder(node *root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);       
    cout << root->data << " ";  
    inorder(root->right);      
}
void postorder(node *root) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left);       
    postorder(root->right);      
    cout << root->data << " ";  
}

int main() {
    cout<<"enter root: ";
    cout<<endl;
    node *root = create(); 
    cout << "Preorder traversal: ";
    preorder(root); 
    cout<<endl;
    cout<<"Inorder traversal: ";
    inorder(root); 
    cout<<endl;
    cout<<"Postorder traversal: ";
    postorder(root);
}
