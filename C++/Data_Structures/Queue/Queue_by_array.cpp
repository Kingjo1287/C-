#include <iostream>
using namespace std;
const int SIZE = 15;
int front = -1;
int rear = -1;
int queue[SIZE];

void insertion(int value){
    if(rear == SIZE-1){
        cout<<"Queue is full. Overflo"<<endl;
    }
    else{
        if(front == -1 && rear == -1){
            rear = front = 0;
        }
        rear++;
        cout<<"value added. ";
        queue[rear] = value;
        cout<<queue[rear]<<endl;
    }
}

void deletion(){
    if(front == rear){
        cout<<"Queue is empty"<<endl;
    }
    else{
        if(front == rear){
            front = rear = -1;
        }
        cout<<"Element deleted "<<endl;
        front++;
        
       
    }

}

void print(){
    if(rear == -1){
        return;
    }
    for(int i = front; i<=rear; i++){
        cout<<queue[i]<<endl;
    }
}



int main(){


    int option, w,value;

    do{
        cout<<"==========MAIN==========="<<endl;
        cout<<"To insert Press 1."<<endl;
        cout<<"To Delete Press 2."<<endl;
        cout<<"To print Press 3."<<endl;
        cout<<"Press 4 to exit"<<endl;
        cin>>option;
        cout<<"-----------"<<endl;

        switch (option)
        {
        case 1:
            cout<<"enter value to push"<<endl;
            cin>>value;
            insertion(value);
            break;
        case 2:
            deletion();
            break;
        case 3:
            print();
            break;
        default:
            break;
        }
    }while(option != 4);

   
    

    return 0;

}