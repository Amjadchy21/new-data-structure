#include<bits/stdc++.h>
using namespace std;

void print(list<int>l)
{
    list<int>:: iterator a= l.begin();
    while(a!=l.end())
    {
        cout<<*a<<" ";
        a++;
    }
    cout<<endl;
}
void rev(list<int>l)
{
    auto a = l.end();
    advance(a,l.size());
    auto b = l.begin();
    advance(b,-1);
    while(a!=b)
    {
        cout<<*a<<" ";
        a--;
    }
    cout<<endl;
}
void Insert(list<int>&l ,int index ,int value)
{
    auto a = l.begin();
    advance(a,index);
    l.insert(a,value);
}
void Delete(list<int>&l ,int index)
{
    list<int>::iterator a = l.begin();
    advance(a,index);
    l.erase(a);
}
int main()
{
    list<int>l;
    l.push_front(4);
    l.push_front(3);
    l.push_front(2);
    l.push_front(1);
    print(l);
    l.push_back(5);
    l.push_back(6);
    print(l);
    l.pop_back();
    print(l);
    l.pop_front();
    print(l);
    Insert(l,1,100);
    print(l);
    Delete(l,3);
    print(l);
    rev(l);
    cout<<"Size = "<<l.size()<<endl;
    cout<<"Empty = "<<l.empty()<<endl;
}
