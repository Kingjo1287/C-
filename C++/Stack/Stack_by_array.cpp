#include <iostream>
using namespace std;
const int SIZE = 10;
int top = -1, stack[SIZE];

void push(int value){
    if(top == SIZE-1){
        cout<<"Stack is full"<<endl;
        return;
    }
    top++;
    cout<<"value added at the top ";
    stack[top] = value;
    cout<<stack[top]<<endl;

}

void pop(){
    if(top == -1){
        cout<<"Stack is empty. Action can not be performed"<<endl;
        return;
    }
    top--;
}

void print(){
    if(top == -1){
        cout<<"Stack is empty"<<endl;
        return;
    }
    for(int i = top; i>=0; i--){
        cout<<stack[i]<<endl;
    }
}


int main(){ 

    int option, w,value;

    do{
        cout<<"==========MAIN==========="<<endl;
        cout<<"To push Press 1."<<endl;
        cout<<"To Pop Press 2."<<endl;
        cout<<"To print Press 3."<<endl;
        cout<<"Press 4 to exit"<<endl;
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
        default:
            break;
        }
    }while(option != 4);


    
}
