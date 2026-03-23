#include <iostream>
using namespace std;

class Stack{
    int top;
    int capacity;
    int *arr;
    public:
    Stack(int a){
        top=-1;
        capacity=a;
        arr = new int[capacity];
    }

    bool isFull(){
        return top==capacity-1;
    }
    bool isEmpty(){
        return top==-1;
    }

    void push(int x){
        if(!isFull()){
        ++top;
        arr[top]=x;
        }
    }
    int pop(){
        int tmp=arr[top];
        if(isEmpty()){
            return -1;
        }
        else{
            --top;
            return tmp;
        }
    }
};

// class Story{
//     private:
//     bool filter_applied;
//     public:
//     string caption;
// };
int main(){
    Stack s(6);
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.pop()<<endl;
    return 0;
}