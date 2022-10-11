#include <iostream>
using namespace std;

struct Node{
    int value;
    Node *next;
    Node *perv;
};
Node *head;
Node *Get_New_Node(int value){
    Node *new_node;
    new_node = new Node();
    new_node->value = value;
    new_node->next = NULL;
    new_node->perv = NULL;
    return new_node;
}

void InsertAtHead(int value){
    Node *new_Node = Get_New_Node(value);
    if(head == NULL){
        head = new_Node;
    }
    else{
        new_Node->next = head;
        head->perv = new_Node;
        head = new_Node; 
    }
}

void InserAtEnd(int value){
    Node *new_node = Get_New_Node(value);
    if(head == NULL){
        head = new_node;
    }
    else{
        Node *temp = head;
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->perv = temp;
    }

}

void print(){
    Node *temp = head;
    if(temp == NULL){
        return;
    }
    cout<<"NULL<-->";
    while(temp != NULL){
        cout<<temp->value<<"<-->";
        temp = temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}

void print_Reverse(){
    Node *temp = head;
    if(temp == NULL){
        return;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }
    cout<<"NULL<-->";
    while(temp != NULL){
        cout<<temp->value<<"<-->";
        temp = temp->perv;
    }
    cout<<"NULL";
    cout<<endl;


}




int main(){

    head = NULL;

    InsertAtHead(3);
    InsertAtHead(2);
    InsertAtHead(1);
    InserAtEnd(4);
    InserAtEnd(5);
    InserAtEnd(6);

    print();
    print_Reverse();

    return 0;

}