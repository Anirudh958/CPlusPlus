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
    return 0;
}