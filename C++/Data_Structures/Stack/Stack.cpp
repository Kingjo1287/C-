#include <iostream>

using namespace std;

struct Node{
    int value;
    Node *next;
};

Node *Top;

Node *create_node(int value){
    Node *new_node;
    new_node = new Node();
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}
void push(int value){
    Node *new_node = create_node(value);

    if(Top == NULL){
        Top = new_node;
    }
    else{
        new_node->next = Top;
        Top = new_node;
    }

}

void peek(){
    if(Top == NULL){
        cout<<"Stack is empty"<<endl;
        return;                           
    }
    cout<<"Top value of stack is "<<Top->value<<endl;;
}

void pop(){
    Node *temp = Top;
    if(Top == NULL){
        cout<<"There is no data in stack"<<endl;
        return;
    }
    Top = temp->next;
    delete temp;
}

void IsEmpty(){
    if(Top == NULL){
        cout<<"True"<<endl;
        return;
    }
    cout<<"False"<<endl;
    
}

void print(){
    Node *temp = Top;
    while(temp != NULL){
        cout<<temp->value<<endl;
        cout<<"="<<endl;
        temp = temp->next;
    }
    cout<<"======"<<endl;
}

int main(){
    Top = NULL;
     int option, w,value;
    do{
        cout<<"==========MAIN==========="<<endl;
        cout<<"To push Press 1."<<endl;
        cout<<"To Pop Press 2."<<endl;
        cout<<"To print Press 3."<<endl;
        cout<<"To peek Press 4."<<endl;
        cout<<"To check is empty Press 5."<<endl;
        cout<<"Press 6 to exit"<<endl;
        cin>>option;
        cout<<"-----------"<<endl;

        switch (option)
        {
        case 1:
            cout<<"enter value to push"<<endl;
            cin>>value;
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            print();
            break;
        case 4:
            peek();
            break;
        case 5:
            IsEmpty();
            break;
        default:
            break;
        }
    }while(option != 6);
   
    
    return 0;

}

