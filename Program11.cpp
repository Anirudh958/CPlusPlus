#include <iostream>
using namespace std;

void functionCountry(string country="Norway"){
    cout<<country<<endl;
}
int main(){
    functionCountry();
    functionCountry("Sweden");
    functionCountry("France");
    return 0;
}