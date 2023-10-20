#include<bits/stdc++.h>
using namespace std;

template<class T>
class Stack
{
public:
    T *a;
    int stack_size;
    int stack_cap;
    Stack()
    {
        a = new T[1];
        stack_cap = 1;
        stack_size = 0;
    }
    void increase_size()
    {
        T *tmp;
        tmp = new T[stack_cap*2];
        for(int i=0;i<stack_cap;i++)
            tmp[i] = a[i];
        swap(a,tmp);
        stack_cap*=2;
    }
    void push(T value)
    {
        if(stack_size+1>stack_cap)
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
            cout<<"Empty"<<endl;
            return;
        }
        stack_size--;
    }
    T top()
    {
        if(stack_size == 0)
        {
            cout<<"Empty"<<endl;
            T a;
            return a;
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
    Stack<int>st;
    st.push(3);
    st.push(4);
    st.push(6);
    st.push(2);
    st.push(5);


    Stack<int>tmp;

    while(st.getSize() > 0)
    {
        int t = st.top();
        st.pop();
        while(tmp.getSize() > 0)
        {
            if(tmp.top() < t)
            {
                break;
            }
            st.push(tmp.top());
            tmp.pop();
        }
        tmp.push(t);
    }
    swap(st,tmp);
    while(st.getSize() > 0)
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}
