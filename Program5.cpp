#include <iostream>
// using namespace std;


namespace first{
    int x=0;
}
int main(){
    int x=1;
    std::cout<<first::x<<std::endl;
    std::cout<<x<<std::endl;
    return 0;
}
// namespace is a solution for preventing naming conflicts in large production. Each entity needs a unique name.
// A namespace allows for identically named entities
// as long as the namespaces are different.