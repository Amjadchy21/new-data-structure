#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    //insert at LAST.......  O(1)
    st.push(30);
    st.push(20);
    st.push(10);
    st.push(40);
    //delete at LAST.......  O(1)
    st.pop();
    //print TOP element.........  O(1)
    cout<<"TOP = "<<st.top()<<endl;
    //SIZE ............  O(1)
    cout<<"STACK SIZE = "<<st.size()<<endl;

    stack<int>tmp;
    tmp.push(st.top());
    st.pop();
    while(st.size()>0)
    {
        int a = st.top();
        st.pop();
        while(tmp.top()>a)
        {
            st.push(tmp.top());
            tmp.pop();
        }
        tmp.push(a);
    }
    swap(st,tmp);
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();



    return 0;
}
