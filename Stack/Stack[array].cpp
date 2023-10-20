#include<bits/stdc++.h>
using namespace std;

const int max_size = 500;
class Stack
{
public:
    int a[max_size];
    int stack_size;
    Stack()
    {
        stack_size = 0;
    }

    void push(int value)
    {
        if(stack_size+1 > max_size)
        {
            cout<<"Stack is full"<<endl;
            return;
        }
        a[stack_size] = value;
        stack_size++;
    }
    void pop()
    {
        if(stack_size == 0)
        {
            cout<<"Stack is empty"<<endl;
            return;
        }
        stack_size--;
    }
    int top()
    {
        if(stack_size == 0)
        {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return a[stack_size-1];
    }
    int getSize()
    {
        return stack_size;
    }
};
int main()
{
    Stack st;
    cout<<"Number of elements insert = ";
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int p;
        cin>>p;
        st.push(p);
    }
    for(int i=0;i<n;i++)
    {
        cout<<"TOP ELements ->"<<st.top()<<endl;
        st.pop();
    }


    return 0;
}
