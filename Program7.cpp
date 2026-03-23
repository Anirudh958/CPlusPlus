#include <iostream>
using namespace std;

int main(){

    int students=20;
    students=students+1;
    cout<<students<<endl;

    int x=3.14;
    double x2 =(int)3.14;
    cout<<x<<endl;
    cout<<x2<<endl;
    cout<<(char)100<<endl;

    int age;
    cin>>age;
    string name;
    getline(cin >>ws,name);
    cout<<"Your name is "<<name<<" and your age is "<<age<<endl;
    return 0;
}