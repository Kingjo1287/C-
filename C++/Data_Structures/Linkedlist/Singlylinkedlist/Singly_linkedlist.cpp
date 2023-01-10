// Name: Zohaib Ahmad
// Date: 09/10/2022
#include <iostream>
using namespace std;

// Structure of a Node
struct Node
{
    int value;
    Node *next;
};

// Global head reference variable
Node *head;
//----------------------------------------------------------------------------------------------------------------
// Will insert node at the beginning where the head is located
void insertFirst(int value)
{
    Node *new_node = new Node();
    new_node->value = value;

    // In case the linkedlist is empty
    if (head == NULL)
    {
        head = new_node;
    }
    // In case the linked list has existing nodes
    else
    {
        new_node->next = head;
        head = new_node;
    }
}
//----------------------------------------------------------------------------------------------------------------
// Will insert new node at the end where tail is located
void insertLast(int value)
{
    Node *new_node;
    new_node = new Node();
    new_node->value = value;
    // if list is empty
    if (head == NULL)
    {
        head = new_node;
    }

    // Will traverse and put the new node at the end
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}
//----------------------------------------------------------------------------------------------------------------
void insertAtPosition(int value, int position) // Will insert Node at given position
{
    Node *new_node;
    new_node = new Node();
    new_node->value = value;
    if (position == 1)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        Node *temp = head;
        for (int i = 0; i < position - 2; i++)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}
//----------------------------------------------------------------------------------------------------------------
void deletion_by_value(int value)
{
    Node *temp = head;
    if (head->value == value)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        Node *temp2 = head;
        while (temp2->next != NULL)
        {
            if (temp2->next->value == value)
            {
                temp = temp2->next;
                temp2->next = temp->next;
                delete temp;
                return;
            }
            else
            {
                temp2 = temp2->next;
            }
        
        }
        cout<<"Data not found"<<endl;
    }
}
//----------------------------------------------------------------------------------------------------------------
void deletion_by_Position(int position)
{
    Node *temp = head;
    if (position == 1)
    {
        head = temp->next;
        delete temp;
    }
    else
    {
        Node *temp_1;
        for (int i = 0; i < position - 2; i++)
        {
            temp = temp->next;
        }
        temp_1 = temp->next;
        temp->next = temp_1->next;
        delete temp_1;
    }
}
//----------------------------------------------------------------------------------------------------------------
void Reverse()
{
    Node *current_node, *previous_node, *next_node;
    current_node = head;
    previous_node = NULL;
    while (current_node != NULL)
    {
        next_node = current_node->next;
        current_node->next = previous_node;
        previous_node = current_node;
        current_node = next_node;

        current_node = next_node;
    }
    head = previous_node;
}
//----------------------------------------------------------------------------------------------------

//not implemented......
void bubble_sort(){
    Node *temp = head;
    Node *temp2 = head;
    Node* p1 , *p2;
    
    while(temp2!= NULL){
        while(temp->next != NULL){
            if(temp->value>temp->next->value){
               p1 = temp->next;
               p2 = p1->next;

               p1->next = temp;
               temp->next = p2;
              
                 
            }
        temp = temp->next;
        }
        head = temp;
        
    temp2= temp2->next;
    }
    return;
}




//----------------------------------------------------------------------------------------------------------------
// Will display values through traversing
void display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " --> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
//---------------------------------------------------------------------------------------------------------------
int main()
{
    head = NULL;

    int option, position,value;

    do{
        cout<<"==========MAIN==========="<<endl;
        cout<<"To insert data at head Press 1."<<endl;
        cout<<"To insert data at tail Press 2."<<endl;
        cout<<"To insert data at a spacific position Press 3."<<endl;
        cout<<"To delete any data Press 4."<<endl;
        cout<<"To delete data at any position Press 5."<<endl;
        cout<<"To reverse the linkedlist Press 6."<<endl;
        cout<<"To Print linkedlilst Press 7."<<endl;
        cout<<"To sort linkedlist Press 8."<<endl;
        cout<<"Press 9 to exit"<<endl;
        cin>>option;
        cout<<"-----------"<<endl;

        switch (option)
        {
        case 1:
            cout<<"Enter the data"<<endl;
            cin>>value;
            insertFirst(value);
            break;
        case 2:
            cout<<"Enter the data"<<endl;
            cin>>value;
            insertLast(value);
            break;
        case 3:
            cout<<"Enter the data"<<endl;
            cin>>value;
            cout<<"Enter the position"<<endl;
            cin>>position;
            insertAtPosition(value,position); 
            break;
        case 4: 
            cout<<"Enter the data that you want to delete"<<endl;
            cin>>value;
            deletion_by_value(value);
            break;
        case 5:
            cout<<"Enter the position at which you want to delete data"<<endl;
            cin>>position;
            deletion_by_Position(position);
            break;
        case 6:
            Reverse();
            break;
        case 7:
            display();
            break;
        case 8:
            bubble_sort();
            break;
        default:
            break;
        }
    }while(option != 9);

    return 0;
}