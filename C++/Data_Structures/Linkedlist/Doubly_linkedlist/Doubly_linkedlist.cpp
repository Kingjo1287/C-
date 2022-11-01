// Zohaib Ahmad
//SP21-BCS-048
// 11/10/2022
#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
    Node *perv;
};
Node *head;
//---------------------------------------------------------------------------------------------------
Node *Get_New_Node(int value)
{ // Function to make a new Node.
    Node *new_node;
    new_node = new Node();
    new_node->value = value;
    new_node->next = NULL;
    new_node->perv = NULL;
    return new_node;
}
//-----------------------------------------------------------------------------------------------------
void InsertAtHead(int value)
{ // Will insert a new Node at head
    Node *new_Node = Get_New_Node(value);
    if (head == NULL)
    {
        head = new_Node;
    }
    else
    {
        new_Node->next = head;
        head->perv = new_Node;
        head = new_Node;
    }
}
//--------------------------------------------------------------------------------------------------------
void InserAtEnd(int value)
{ // Will insert a new Node at the end of the linkedlist
    Node *new_node = Get_New_Node(value);
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->perv = temp;
    }
}
//--------------------------------------------------------------------------------------------------------------
void deletion_by_value(int value)
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    if (head->value == value)
    {
        temp->next->perv = NULL;
        head = temp->next;
        return;
    }
    while (temp->next != NULL)
    {
        if (temp->next->value == value)
        {
            Node *Next;
            Next = temp->next;
            if (Next->next == NULL)
            {
                temp->next = NULL;
                delete Next;
                return;
            }
            Next->next->perv = temp;
            temp->next = Next->next;
            delete Next;
            return;
        }
        temp = temp->next;
    }
    cout << "Value not found" << endl;
}
//----------------------------------------------------------------------------------------------------------------
void deletion_by_position(int position)
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (position == 1)
    {
        temp->next->perv = NULL;
        head = temp->next;
        return;
    }
    for (int i = 0; i < position - 2; i++)
    {
        temp = temp->next;
    }
    Node *Next;
    Next = temp->next;
    if (Next->next == NULL)
    {
        temp->next = NULL;
        delete Next;
        return;
    }
    Next->next->perv = temp;
    temp->next = Next->next;
    delete Next;
    return;
}
//-----------------------------------------------------------------------------------------------------------------
void print()
{ // Function to print values of linkedlist
    Node *temp = head;
    if (temp == NULL)
    {
        return;
    }
    cout << "NULL<-->";
    while (temp != NULL)
    {
        cout << temp->value << "<-->";
        temp = temp->next;
    }
    cout << "NULL";
    cout << endl;
}
//--------------------------------------------------------------------------------------------------------------
void print_Reverse()
{ // Will print the linkedlist in reverse order
    Node *temp = head;
    if (temp == NULL)
    {
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    cout << "NULL<-->";
    while (temp != NULL)
    {
        cout << temp->value << "<-->";
        temp = temp->perv;
    }
    cout << "NULL";
    cout << endl;
}
//------------------------------------------------------------------------------------------------------------
int main()
{
    head = NULL;
    int num;
    cout << "Enter the number of nodes You want to create" << endl;
    cin >> num;
    int value;
    cout << "Please enter the values of the nodes" << endl;
    for (int i = 0; i < num; i++)
    {
        cin >> value;
        InserAtEnd(value);
        print();
    }
    int c;
    cout << "For deletion by value press 1. for deletion by position press 2." << endl;
    cin >> c;
    switch (c)
    {
    case 1:
        int value1;
        cout << "Please enter the value you want to delete";
        cin >> value1;
        deletion_by_value(value1);
        print();
        break;
    case 2:
        int position;
        cout << "Pleasae enter the position of the node";
        cin >> position;
        deletion_by_position(position);
        print();
    default:
        cout << "Pleasae enter the correct value";
        break;
    }

    return 0;
}