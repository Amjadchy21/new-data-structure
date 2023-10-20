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
//            assert(false);
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
    cout<<"Original stack : ";
    st.push(1);
    cout<<"1 ";
    st.push(5);
    cout<<"5 ";
    st.push(5);
    cout<<"5 ";
    st.push(2);
    cout<<"2 ";
    st.push(3);
    cout<<"3 ";
    st.push(8);
    cout<<"8 ";
    cout<<endl;

//  Sorting a Stack.............
    Stack tmp;
    tmp.push(st.top());
    st.pop();
    while(st.getSize()>0)
    {
        int a = st.top();
        st.pop();
        while(tmp.top()<a)
        {
            st.push(tmp.top());
            tmp.pop();
        }
        tmp.push(a);
    }
    swap(tmp,st);
    cout<<"Sorted stack : ";
    while(st.getSize()>0)
    {
        cout<<st.top()<<" ";
        st.pop();
    }

}

