#include<iostream>
#include<list>
#include<iterator>
using namespace std;

void printList(list<int>ll){

    list<int>::iterator itr;

    for(itr = ll.begin(); itr != ll.end(); itr++){
        cout<<(*itr)<<"->";
    }

    cout<<"NULL"<<endl;

}

int main(){

    list<int>ll;


    ll.push_front(0);
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    printList(ll);

    cout<<ll.size()<<endl;

    ll.pop_front();
    ll.pop_back();

    list<int>::iterator itr;
    itr = ll.begin();
    advance(itr,2);
    ll.insert(itr,99);

    cout<<ll.front()<<endl;
    cout<<ll.back()<<endl;

    printList(ll);
    return 0;
}