#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    for(int i=0;i<=st.size();i++){
        cout << st.top() << endl;
        st.pop();
    }
    stack<int> st2;
    st2.push(3);
    st2.push(4);
    st2.push(5);
    stack<int> st3(st2); //make a copy of st2
    while(!st3.empty()){
        cout<<st3.top()<<endl;
        st3.pop();
    }
    return 0;
}