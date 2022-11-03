#include <iostream>
using namespace std;

void insertion_sort(int arr[], int size){
    int j, temp;
    for(int i=1; i< size; i++){
        temp = arr[i];
        j = i-1;

        while(temp < arr[j] && j>=0){
            arr[j+1] = arr[j];
            j--;

        }
        arr[j+1] = temp;

    }
    cout<<"-------------------------"<<endl;
    cout<<"Sorted array"<<endl;
    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" "<<endl;
    }
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

    insertion_sort(arr, size);
}