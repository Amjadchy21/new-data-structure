#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *nxt;
};
class LinkedList{
public:
    node *head;
    int sz;
    LinkedList()
    {
        head = NULL;
        sz = 0;
    }
    //create a new node...
    node *createNewNode(int value)
    {
        node *newNode = new node;
        newNode->data = value;
        newNode->nxt = NULL;
        return newNode;
    }

    //insert value at head position...
    void insertAtHead(int value)
    {
        sz++;
        node *a = createNewNode(value);
        if(head == NULL)
        {
            head = a;
            return;
        }
        a->nxt = head;
        head = a;
    }
    void insertAtTail(int value)
    {
        sz++;
        node *a = createNewNode(value);
        if(head == NULL)
        {
            head = a;
            return;
        }
        node *b = head;
        int cur_index = 0;
        while(cur_index != sz-2)
        {
            b = b->nxt;
            cur_index++;
        }
        b->nxt = a;
    }
    void traverse()
    {
        node *a = head;
        while(a!=NULL)
        {
            cout<<a->data<<" ";
            a=a->nxt;
        }
        cout<<endl;
    }
    int searchDistinctValue(int value)
    {
        node *a = head;
        int index = 0;
        while(a!=NULL)
        {
            if(a->data == value)
            {
                return index;
            }
            a=a->nxt;
            index++;
        }
        return -1;
    }
    void searchAllValue(int value)
    {
        node *a = head;
        int index = 0;
        while(a!=NULL)
        {
            if(a->data == value)
            {
                cout<<value<<" is found at position -> "<<index<<endl;
            }
            a=a->nxt;
            index++;
        }
    }

//    O(Size of Linked List) ->

   int getSize()
   {
//        int sz = 0;
//        node *a = head;
//        while(a!=NULL)
//        {
//            sz++;
//            a = a->nxt;
//        }
        return sz;
    }
    void insertAtAnyIndex(int index,int value)
    {
        if(index < 0 || index>sz)
        {
            return;
        }
        if(index==0)
        {
            insertAtHead(value);
            return;
        }
        sz++;
        node *a = head;
        int cur_index = 0;
        while(cur_index!=index-1)
        {
            a = a->nxt;
            cur_index++;
        }
        node *newNode = createNewNode(value);
        newNode->nxt = a->nxt;
        a->nxt = newNode;
    }
    void deleteAtHead()
    {
        if(head == NULL)
        {
            return;
        }
        sz--;
        node *a = head;
        head = a->nxt;
        delete a;
    }
    void deleteAtAnyIndex(int index)
    {
        if(index < 0 || index > sz-1)
        {
            return;
        }
        if(index==0)
        {
            deleteAtHead();
            return;
        }
        sz--;
        node *a = head;
        int cur_index = 0;
        while(cur_index!=index-1)
        {
            a = a->nxt;
            cur_index++;
        }
        node *b = a->nxt;
        a->nxt = b->nxt;
        delete b;
    }
    void insertAfterValue(int value,int data)
    {
        node *a = head;
        while(a != NULL)
        {
            if(a->data == value)
            {
                break;
            }
            a = a->nxt;
        }
        if(a == NULL)
        {
            cout<<value<<" doesn't exist"<<endl;
            return;
        }
        sz++;
        node *newNode = createNewNode(data);
        newNode->nxt = a->nxt;
        a->nxt = newNode;
    }
    void reversePrint2(node *a)
    {
        if(a == NULL)
        {
            return;
        }
        reversePrint2(a->nxt);
        cout<<a->data<<" ";
    }
    void reversePrint()
    {
        cout<<"Reverse print -> ";
        reversePrint2(head);
        cout<<endl;
    }

};

int main()
{
    LinkedList l;
    l.insertAtHead(1);
    l.insertAtHead(2);
    l.insertAtHead(3);
    l.insertAtHead(4);
    l.insertAtHead(2);
    l.insertAtTail(100);

    l.traverse();
    cout<<"2 is found at "<<l.searchDistinctValue(2)<<endl;
    l.searchAllValue(2);

    cout<<"Size -> "<<l.getSize()<<endl;

    l.insertAtAnyIndex(2,200);
    l.traverse();
    l.insertAtAnyIndex(6,600);
    l.traverse();
    cout<<"New Size -> "<<l.getSize()<<endl;
    cout<<endl;

    l.deleteAtHead();
    l.traverse();
    cout<<"After deleteAtHead New Size -> "<<l.getSize()<<endl;
    cout<<endl;

    l.deleteAtAnyIndex(3);
    l.traverse();
    cout<<"After deleteAtAnyIndex new Size -> "<<l.getSize()<<endl;
    cout<<endl;

    l.insertAfterValue(2,100);
    l.traverse();
    cout<<"After insertAfterValue new Size -> "<<l.getSize()<<endl;
    cout<<endl;
    l.insertAfterValue(3,100);
    l.traverse();
    cout<<"After insertAfterValue new Size -> "<<l.getSize()<<endl;
    cout<<endl;

    l.reversePrint();


    return 0;
}
