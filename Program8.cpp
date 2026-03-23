#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double x;
    double y;
    double z;
    cout <<"enter x: ";
    cin >>x;
    cout <<"enter y: "<<endl;
    cin >>y;

    x=pow(x,2);
    y=pow(y,2);
    z=sqrt(x+y);

    cout<<"z is: "<<z<<endl;

    return 0;
}