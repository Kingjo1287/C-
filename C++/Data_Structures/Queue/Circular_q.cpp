//ZOHAIB AHMAD
//SP21_BCS_048
//26-12-2022  

#include<iostream>
using namespace std;
const int SIZE =5;
int my_queue[SIZE];
int front =-1;
int rear= -1;

bool isempty(){
    if(front==-1 && rear==-1){
        return true;
    }
    else{
        return false;
    }
}
void enqueue(int value){
    if((rear+1)%SIZE==front){
        std::cout << "Queue is full" << std::endl;
        return;
    }
    if(isempty()){
        front=rear=0;
    }
    else{
        rear=(rear+1)%SIZE;
    }
    my_queue[rear]=value;
    
}

void dequeue(){
    if(isempty()){
        std::cout << "Queue is empty" << std::endl;
        return;
    }
    else if(front == rear){
        front=rear=-1;
    }
    else{
        front = (front+1)%SIZE;
    }
    
}

void Print()
	{
	    if(isempty()){
	        std::cout << "Queue is empty" << std::endl;
	        return;
	    }
		int count = (rear+SIZE-front)%SIZE + 1;
		cout<<"Queue       : ";
		for(int i = 0; i <count; i++)
		{
			int index = (front+i) % SIZE;
			cout<<my_queue[index]<<" ";
		}
		cout<<"\n\n";
	}


int main(){
    enqueue(5);
    enqueue(85);
    enqueue(65);
    enqueue(12);
    enqueue(53);
    Print();
    dequeue();
    Print();
    dequeue();
    Print();
    enqueue(8);
    Print();
}