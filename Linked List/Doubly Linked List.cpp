#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *nxt;
    node *prv;
};
class DoublyLinkedList{
public:
    node *head;
    int sz;
    DoublyLinkedList()
    {
       head = NULL;
       sz = 0;
    }
    // Creates a new node......
    node *createNewNode(int value)
    {
        node *newNode = new node;
        newNode->data = value;
        newNode->nxt = NULL;
        newNode->prv = NULL;
        return newNode;
    }
    // insert Value at Head......O(1)
    void insertAtHead(int value)
    {
        sz++;
        node *newNode = createNewNode(value);
        if(head == NULL)
        {
            head = newNode;
            return;
        }
        node *a = head;
        newNode->nxt = a;
        a->prv = newNode;
        head = newNode;
    }
    //insert value at any position.......O(n)
    void insertAtAnyIndex(int index , int value)
    {
        if(index > sz || index < 0)
        {
            return;
        }
        if(index == 0)
        {
            insertAtHead(value);
            return;
        }
        node *a = head;
        int cur_index = 0;
        while(cur_index != index-1)
        {
            a = a->nxt;
            cur_index++;
        }
        node *newNode = createNewNode(value);
        newNode->nxt = a->nxt;
        newNode->prv = a;
        node *b = a->nxt;
        b->prv = newNode;
        a->nxt = newNode;
        sz++;

    }
    //Traverse ........O(n)
    void traverse()
    {
        node *a = head;
        while(a!=NULL)
        {
            cout<<a->data<<" ";
            a = a->nxt;
        }
        cout<<endl;
    }
    //delete the given index......O(n)
    void Delete(int index)
    {
        if(index < 0 || index >= sz)
        {
            return;
        }
        node *a = head;
        int cur_index = 0;
        while(cur_index != index)
        {
            a = a->nxt;
            cur_index++;
        }
        node *b = a->prv;
        node *c = a->nxt;
        if(b!=NULL)
        {
            b->nxt = c;
        }
        if(c!=NULL)
        {
            c->prv = b;
        }
        delete a;
        if(index == 0)
        {
            head = c;
        }
        sz--;
    }

    void Reverse()
    {
        if(head == NULL)
        {
            return;
        }
        node *a = head;
        int cur_index = 0;
        while(cur_index != sz-1)
        {
            a = a->nxt;
            cur_index++;
        }
        node *b = head;
        while(b != NULL)
        {
            swap(b->nxt , b->prv);
            b = b->prv;
        }
        head = a;
    }
    // Tottal Size.........
    int getSize()
    {
        return sz;
    }

};
int main()
{
    DoublyLinkedList dl;
    dl.insertAtHead(10);
    dl.insertAtHead(20);
    dl.insertAtHead(30);

    dl.traverse();
    cout<<"SIZE -> "<<dl.getSize()<<endl;

    dl.insertAtAnyIndex(2,50);
    dl.traverse();
    cout<<"SIZE -> "<<dl.getSize()<<endl;

    dl.Delete(0);
    dl.traverse();
    cout<<"SIZE -> "<<dl.getSize()<<endl;

    dl.Reverse();
    dl.traverse();

    return 0;
}
