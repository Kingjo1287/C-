#include <iostream>
using namespace std;

void inc_sort(int arr[], int size){
    bool isswap;
    for(int i = 1; i< size; i++){
        isswap = false;
        for(int j = 0; j< (size-i); j++){
            if(arr[j]> arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isswap = true;
            }
        }
        if(isswap == false){
            cout<<"Values are already sorted"<<endl;
            break;
        }
    }

    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" "<<endl;
    }
}

void decr_sort(int arr[], int size){
    bool isswap = false;
    for(int i = 0; i< size-1; i++){
        for(int j = 0; j< (size-i); j++){
            if(arr[j]< arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isswap = true;
            }
        }
        if(isswap == false){
            cout<<"Values are already sorted"<<endl;
            break;
        }
    }
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
    int option;
    do{
        cout<<"==========MAIN==========="<<endl;
        cout<<"To sort in increasing order Press 1."<<endl;
        cout<<"To sort in decreasing order Press 2."<<endl;
        cout<<"Press 3 to exit"<<endl;
        cin>>option;
        cout<<"-----------"<<endl;

        switch (option)
        {
        case 1:
            inc_sort(arr, size); 
            break;
        case 2:
            decr_sort(arr, size);
            break;
       
        default:
            break;
        }
    }while(option != 3);


    return 0;



}