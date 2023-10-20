#include<bits/stdc++.h>
using namespace std;

const int Max_size = 500;
class Stack{
public:
    int a[Max_size];
    int Stack_size;
    Stack()
    {
        Stack_size = 0;
    }
    void push(int value)
    {
        if(Stack_size + 1>Max_size)
        {
            cout<<"Overflow"<<endl;
            return;
        }
        a[Stack_size] = value;
        Stack_size++;
    }

    void pop()
    {
        if(Stack_size == 0)
        {
            cout<<"UNDERFLOW"<<endl;
            return;
        }
        Stack_size--;
    }
    int top()
    {
        if(Stack_size == 0)
        {
            return -1;
        }
        return a[Stack_size-1];
    }
    int getSize()
    {
        return Stack_size;
    }
};
int main()
{
    Stack st;
    st.push(2);
    st.push(4);
   // cout<<st.getSize()<<endl;
    cout<<"TOP -> "<<st.top()<<endl;
    st.pop();
    cout<<"TOP -> "<<st.top()<<endl;
    cout<<"Size -> "<<st.getSize()<<endl;
    st.pop();
    st.pop();
    cout<<"TOP -> "<<st.top()<<endl;


    return 0;
}
