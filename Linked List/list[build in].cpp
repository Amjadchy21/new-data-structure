#include<bits/stdc++.h>
using namespace std;
//O(n)........
void print(list<int>l)
{
//    auto it = l.begin();
    list<int>::iterator it;
    it = l.begin();
    while(it != l.end())
    {
        cout<<*it<<" ";
        it++;
    }
    cout<<endl;
}
//O(n).....
void Insert(list<int>&l,int value,int index)
{
    auto it = l.begin();
    advance(it,index);
    l.insert(it,value);
}
//O(n).......
void Delete(list<int>&l,int index)
{
    list<int>::iterator it = l.begin();
    advance(it , index);
    l.erase(it);
}
int main()
{
    list<int>l;
    //insert element at head...........
    l.push_front(10);
    l.push_front(20);
    //insert element at tail..........
    l.push_back(15);
    l.push_back(30);
    print(l);
    //delete at head and tail.........
    l.pop_back();
    l.pop_front();
    //insert at any position........
    Insert(l,100,2);
    print(l);
    //Delete at any position......
    Delete(l,1);
    print(l);
    cout<<"Size = "<<l.size()<<endl;

    return 0;
}
