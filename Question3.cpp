#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main(){
    queue<string> line;
    string input;
    while(getline(cin,input)){
        if(input.rfind("Enter",0)==0){
            string visitor=input.substr(6);
            line.push(visitor);
        }
        else if(input=="Exit"){
            if(!line.empty()){
            cout<<line.front()<<" removed"<<endl;
            line.pop();
        }
        else{
            cout<<"No visitors in line"<<endl;
        }
        }
    }
    return 0;
}