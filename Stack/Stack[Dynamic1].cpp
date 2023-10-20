#include<bits/stdc++.h>
using namespace std;


/*class Stack{
public:
    int *a;
    int Stack_size;
    int arr_cap;
    Stack()
    {
        a = new int[1];
        arr_cap = 1;
        Stack_size = 0;
    }

    void increase_size()
    {
        int *tmp;
        tmp = new int[arr_cap*2];
        for(int i=0;i<arr_cap;i++)
            tmp[i] = a[i];
        swap(a,tmp);
        arr_cap = arr_cap*2;
        delete []tmp;
    }

    void push(int value)
    {
        if(Stack_size+1>arr_cap)
        {
            increase_size();
        }
        a[Stack_size] = value;
        Stack_size++;
    }
    void pop()
    {
        if(Stack_size == 0)
        {
            cout<<"UNDERFLOW\n";
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
        Stack_size--;
    }

}; */



class Stack{
public:
    int *a;
    int Stack_size;
    int arr_cap;

    Stack()
    {
        a = new int[1];
        Stack_size = 0;
        arr_cap = 1;
    }

    void increase_size()
    {
        int *tmp;
        tmp = new int[arr_cap*2];
        for(int i=0;i<arr_cap;i++)
            tmp[i] = a[i];
        swap(a,tmp);
        delete []tmp;
        arr_cap = arr_cap*2;
    }
    void push(int value)
    {
        if(Stack_size+1>arr_cap)
        {
            increase_size();
        }
        a[Stack_size] = value;
        Stack_size++;
    }

    void pop()
    {
        if(Stack_size == 0)
        {
            cout<<"UNDERFLOW";
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

};
int main()
{
//    Stack st;
//    st.push(2);
//    st.push(4);
//    cout<<"TOP -> "<<st.top()<<endl;
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(3);

    for(int i=0;i<st.Stack_size;i++)
    {
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}
