#include <iostream>

using namespace std;

struct Node{
    int value;
    Node *next;
};

Node *head;

Node *create_node(int value){
    Node *new_node;
    new_node = new Node();
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}
void push(int value){
    Node *new_node = create_node(value);

    if(head == NULL){
        head = new_node;
    }
    else{
        new_node->next = head;
        head = new_node;
    }

}

void pop(){
    Node *temp = head;
    if(head == NULL){
        cout<<"There is no data in stack"<<endl;
        return;
    }
    head = temp->next;
    delete temp;
}

void print(){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->value<<endl;
        cout<<"|"<<endl;
        temp = temp->next;
    }
    cout<<"======"<<endl;
}

int main(){
    head = NULL;

    push(2);
    push(3);
    push(5);
    print();
    pop();
    push(6);
    print();
    push(2);
    pop();
    push(7);
    print();
    
    return 0;

}

