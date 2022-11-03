#include <iostream>
#include <array>
using namespace std;

void search(int a[],int size,int value){
    int mid, start=0, end=size-1;

    mid = (start+end)/2;

    while(start<=end){
        if(a[mid] == value){
            cout<<"Value "<<a[mid]<<" found at index "<<mid<<endl;
            
            return;
        }
        else if(a[mid] < value){
            start = mid + 1;
        }
        else{
            end = mid -1; 
        }
        mid = (start + end)/2;
        }
        cout<<"Value not found in the array "<<endl;

}


int main(){
    int size;

    cout<<"Enter the number of elements "<<endl;
    cin>>size;

    int arr[size];

    cout<<"Enter the value of the elements "<<endl;
    for(int i = 0; i < size; i++){
        cin>>arr[i];
    }

    int value;
    cout<<"Enter the value to find ";
    cin>>value;
    search(arr, size,value);


    return 0;

}