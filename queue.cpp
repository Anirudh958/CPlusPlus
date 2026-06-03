#include <iostream>
#include <queue>
using namespace std;
int main(){
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    cout<<"Front Element"<<endl;
    cout<<q1.front()<<endl;
    cout<<"Back Element"<<endl;
    cout<<q1.back()<<endl;
    cout<<"Front Element after pop"<<endl;
    q1.pop();
    cout<<q1.front()<<endl;
    cout<<"Check is the queue is empty or not"<<endl;
    cout<<q1.empty()<<endl;
    queue<int>q2(q1); // make a copy of q1
    cout<<"Elements inside the copy of q1(q2)"<<endl;
    while(!q2.empty()){
        cout<<q2.front()<<endl;
        q2.pop();
    }
    return 0;
}