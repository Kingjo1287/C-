#include <iostream>
using namespace std;

struct Node
{

    string value;
    Node *next;
};

Node *head = NULL;
void insert(string value)
{
    Node *new_node;
    new_node = new Node();
    new_node->value = value;
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
    }
}

void replace(string value, string value2)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->value == value)
        {

            temp->value = value2;
        }
        temp = temp->next;
    }
}

void display()
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->value << "-->";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    insert("school");
    insert("school");
    insert("school");
    insert("college");
    insert("school");
    insert("school");
    insert("school");
    display();

    replace("college", "university");
    display();

    return 0;
}
