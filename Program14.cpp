#include <iostream>
using namespace std;

class ComplexNumber{
    private:
    double real;
    double imag;
    public:
    ComplexNumber(double r,double i):real(r),imag(i){}
    ComplexNumber operator+(const ComplexNumber &c) const{
        return ComplexNumber(real+c.real,imag+c.imag);
    }

    // ostream& operator<<(ostream& os){
    //     os<<real<<" + "<<imag<<"i";
    //     return os;
    // }
    friend ostream& operator<<(ostream& os,const ComplexNumber &c);
};
ostream& operator<<(ostream& os,const ComplexNumber &c){
    if(c.imag>=0){
        cout<<c.real<<" + "<<c.imag<<"i";
    }
    else{
        cout<<c.real<<""<<c.imag<<"i";
    }
    return os;
}
int main(){
ComplexNumber c1(2,5);
ComplexNumber c2(3,6);
ComplexNumber c3=c1+c2;

// cout<<c1;
// c1<<cout;
cout<<c1<<endl;
cout<<c3<<endl;
}