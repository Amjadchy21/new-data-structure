#include<bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int *a;
    int arr_cap;
    int stack_size;
    Stack()
    {
        a = new int[1];
        arr_cap = 1;
        stack_size = 0;
    }
    void increase_size()
    {
        int *tmp;
        tmp = new int[arr_cap*2];
        for(int i=0;i<arr_cap;i++)
            tmp[i] = a[i];
        swap(tmp,a);
        delete []tmp;
        arr_cap = arr_cap*2;
    }

    void push(int value)
    {
        if(stack_size+1>arr_cap)
        {
            increase_size();
        }
        a[stack_size] = value;
        stack_size++;
    }
    void pop()
    {
        if(stack_size == 0)
        {
            cout<<"Stack Empty"<<endl;
            return;
        }
        a[stack_size-1] = 0;
        stack_size--;
    }
    int top()
    {
        if(stack_size == 0)
        {
            cout<<"Stack Empty"<<endl;
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
    st.push(2);
    st.push(4);
    st.push(6);
    cout<<"Top -> "<<st.top()<<endl;
    st.pop();
    cout<<"Top -> "<<st.top()<<endl;
    st.pop();
    st.pop();
    st.pop();
    cout<<"Top -> "<<st.top()<<endl;
    st.push(20);
    st.push(40);
    st.push(60);
    cout<<"Top -> "<<st.top()<<endl;
    cout<<"Size -> "<<st.getSize()<<endl;


    return 0;
}
