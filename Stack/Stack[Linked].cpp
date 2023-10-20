#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *nxt;
};
class Linked_list
{
public:
    node *head;
    int sz;
    Linked_list()
    {
        head = NULL;
        sz = 0;
    }
    node *createNewNode(int value)
    {
        node *newNode = new node;
        newNode->data = value;
        newNode->nxt = NULL;
        return newNode;
    }
    void insertAtHead(int value)
    {
        sz++;
        node *a = createNewNode(value);
        if(head == NULL)
        {
            head = a;
        }
        a->nxt = head;
        head = a;
    }

    void deleteAtHead()
    {
        node *a = head;
        head = a->nxt;
        delete a;
        sz--;
    }
    int getSize()
    {
        return sz;
    }
};

class Stack
{
public:
    Linked_list l;
    void push(int value)
    {
        l.insertAtHead(value);
    }
    void pop()
    {
        if(l.getSize() == 0)
        {
            cout<<"UNDERFLOW"<<endl;
            return;
        }
        l.deleteAtHead();
    }
    int top()
    {
        if(l.getSize()==0)
        {
            return -1;
        }
        return l.head->data;
    }
    int getSize()
    {
        return l.getSize();
    }

};

int main()
{
    Stack st;
    st.push(2);
    st.push(4);
    st.push(6);

//  Reverse Stack................
    Stack tmp;
    while(st.getSize()>0)
    {
        tmp.push(st.top());
        st.pop();
    }
    swap(st,tmp);
    while(st.getSize()>0)
    {
        cout<<st.top()<<endl;
        st.pop();
    }
}
