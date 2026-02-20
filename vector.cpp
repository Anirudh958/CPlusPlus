#include <iostream>
#include <vector>
using namespace std;
int main() {
    
    // Declares an empty vector
    vector<int> v1;
    
    // Declares vector with given size
    // and fills it with a value
    vector<int> v2(3, 5);  
    
    // Print items of v2
    for (int x : v2) {
        cout << x << " ";
    }
    
    cout << endl;
    
    // Initializes vector using 
    // initializer list.
    vector<int> v3 = {1, 2, 3};  
    
    // Print items of v3
    for (int x : v3) {
        cout << x << " ";
    }
    
    return 0;
}








#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<char> v = {'a', 'f', 'd'};
  
  	// Inserting 'z' at the back
  	v.push_back('z');
  
  	// Inserting 'c' at index 1
  	v.insert(v.begin() + 1, 'c');

  	for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    return 0;
}





#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {10, 20, 30, 40};
    
    // Accessing using operator[]
    cout << "Element at index 2 using []: " << v[2] << endl;
    
    // Accessing using at()
    cout << "Element at index 3 using at(): " << v.at(3) << endl;
    
    // Uncommenting the next line will throw an 
    // out_of_range exception 
    // cout v.at(10)<<endl;
    return 0;
}




#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int>v;
    
    // Check if the vector is empty
    if(v.empty()){
        cout<<"Vector is empty."<<endl;
    }
    
    // Add an element
    v.push_back(100);
    if(!v.empty()){
        cout<<"Vector is not empty. First element "<<v[0]<<endl;
    }
    return 0;
}