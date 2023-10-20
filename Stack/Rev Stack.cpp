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
    Stack<int>a;
    a.push(2);
    a.push(4);
    a.push(6);
    a.push(8);

    Stack<int>tmp;
    while(a.getSize()>0)
    {
        tmp.push(a.top());
        a.pop();
    }
    swap(a,tmp);
    while(a.getSize()>0)
    {
        cout<<a.top()<<endl;
        a.pop();
    }
}
