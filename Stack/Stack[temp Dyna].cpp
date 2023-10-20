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
        for(int i=0; i<stack_cap; i++)
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
//            assert(false);
            T a;
            return a;
        }
        return a[stack_size - 1];
    }
};

int main()
{

    Stack<double>st1;
    st1.push(1.2);
    st1.push(1.3);
    st1.push(1.4);
    st1.push(1.5);
    cout<<st1.top()<<endl;
    st1.pop();
    cout<<st1.top()<<endl;
    st1.pop();
    cout<<st1.top()<<endl;
    st1.pop();
    cout<<st1.top()<<endl;
    st1.pop();
    cout<<st1.top()<<endl;



    return 0;
}
