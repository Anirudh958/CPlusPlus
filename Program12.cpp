#include <iostream>
using namespace std;
struct ListNode{
int value;
ListNode* next;
ListNode(int x):value(x),next(nullptr){}
};

class LinkedList{
    public:
    ListNode* createFromArray(int arr[],int n){
        if(n==0){
            return nullptr;
        }
        ListNode* head =new ListNode(arr[0]);
        ListNode* current =head;
        for(int i=1;i<n;i++){
            current->next=new ListNode(arr[i]);
            current=current->next;
        }
        return head;
    }
    void printList(ListNode* head){
        ListNode* current =head;
        while(current!=nullptr){
            cout<<current->value;
            if(current->next!=nullptr){
                cout<<"-> ";
            }
            current=current->next;
        }
        cout<<" -> nullptr"<<endl;
    }
    void deleteList(ListNode* head){
        while(head!=nullptr){
            ListNode* tmp=head;
            head=head->next;
            delete tmp;
        }
    }
};
int main(){
    LinkedList list;
    int arr[]={1,2,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    ListNode* head=list.createFromArray(arr,n);
    list.printList(head);
    list.deleteList(head);
    return 0;
}