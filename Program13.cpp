#include <iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node(int x):data(x),next(nullptr){}
};

class LinkedList{
    private:
    node* head;
    public:
    LinkedList():head(nullptr){}
    void insertAtBeginning(int x){
        node* newNode=new node(x);
        newNode->next=head;
        head=newNode;
    }
    void insertAtEnd(int x){
        node* newNode= new node(x);
        if(head==nullptr){
            head=newNode;
            return;
        }
        node* current=head;
        while(current->next!=nullptr){
            current=current->next;
        }
        current->next=newNode;
    }
    void insertAtPosition(int x,int position){
        node* newNode= new node(x);
        if(position==0){
            insertAtBeginning(x);
            return;
        }
        node* current=head;
        for(int i=0;i<position-1 && current->next!=nullptr;i++){
            current=current->next;
        }
        if(current->next==nullptr){
            cout<<"out of range"<<endl;
            return;
        }
        newNode->next=current->next;
        current->next=newNode;
    }
    void deleteByValue(int value){
        if(head==nullptr){
            return;
        }
        if(head->data==value){
            node* tmp =head;
            head=head->next;
            delete tmp;
            return;
        }
        node* current=head;
        while(current->next!=nullptr && current->next->data!=value){
            current=current->next;
        }
        if(current->next && current->next->data==value){
            node* tmp=current->next;
            current->next=current->next->next;
            delete tmp;
            return;
        }
    }
    void reverse(){
        node* prev=nullptr;
        node* current=head;
        node* next=nullptr;
        while(current!=nullptr){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        head=prev;
    }
    bool hasCycleNode(){
        if(head==nullptr){
            return false;
        }
        node* slow=head;
        node* fast=head;
        while(slow->next!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
    node* mergeSortedLists(node* list1, node* list2){
        node* dummy = new node(0);
        node* tail=dummy;
        if(list1==nullptr){
            return list2;
        }
        if(list2==nullptr){
            return list1;
        }
        while(list1!=nullptr && list2!=nullptr){
            if(list1->data < list2->data){
                tail->next=list1;
                list1=list1->next;
            }
            else{
                tail->next=list2;
                list2=list2->next;
            }
        }
        if(list1!=nullptr){
            tail->next=list1;
        }
        else{
            tail->next=list2;
        }
        node* mergeList=dummy->next;
        delete dummy;
        return mergeList;
    }
};