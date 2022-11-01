// Name: Zohaib Ahmad
// Date: 09/10/2022

#include <iostream>
using namespace std;

class SinglyLinklist
{
    class Node
    {
    public:
        int value;
        Node *next;
    };
    Node *head;

public:
    SinglyLinklist()
    {
        head = NULL;
    }
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

    void deletion_by_value(int value)
    {
        Node *current = head;
        if (head->value == value)
        {
            current = head;
            head = head->next;
            delete current;
        }
        else
        {

            Node *prev = head;
            while (prev->next != NULL)
            {
                if (prev->next->value == value)
                {
                    current = prev->next;
                    prev->next = current->next;
                    delete current;
                    return;
                }
                else
                {
                    prev = prev->next;
                }
            }
            cout << "Data not found" << endl;
        }
    }

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
};

int main()
{

    SinglyLinklist list;
    list.insertFirst(0);
    list.insertFirst(-1);
    list.insertFirst(-2);
    list.insertLast(1);
    list.insertLast(2);
    list.deletion_by_value(4);
    list.display();
}