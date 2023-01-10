#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* create(){

    int x;
    cout<<"Enter the value: "<<endl;
    cin>> x;

    if(x==-1){
        return 0;
    }

    Node* newNode = new Node();
    newNode->data = x;

    cout<<"enter value for left node: "<<endl;
    newNode->left = create();

    cout<<"enter value for right node: "<<endl;
    newNode->right = create();

    return newNode;

}


int main(){
Node* root;
root = 0;
root = create();
}