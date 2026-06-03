#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct Product{
    int pid;
    string pname;
    double pprice;
    Product* next;
    Product(int id,string name, double price){
        pid=id;
        pname=name;
        pprice=price;
        next=nullptr;
    }
};
class ShopEasy{
    private:
    Product* head;
    public:
    ShopEasy(){
        head=nullptr;
    }
    void addProduct(int id,string name,double price){
        Product* newProduct = new Product(id,name,price);
        newProduct->next=head;
        head=newProduct;
    }
    void deleteProduct(int id){
        if(head==nullptr){
            cout<<"no products to delete"<<endl;
            return;
        }
        if(head->pid==id){
            Product* tmp=head;
            head=head->next;
            delete tmp;
            return;
        }
        Product* current=head;
        while(current->next!=nullptr){
            if(current->next->pid==id){
                Product* tmp =current->next;
                current->next=current->next->next;
                delete tmp;
                return;
            }
        }
    }
    void displayProduct(){
        Product* current=head;
        while(current!=nullptr){
            cout<<"[ "<<current->pid<<" "<<current->pname<<" "<<fixed<<setprecision(2)<<current->pprice<<" ]";
            current=current->next;
            if(current!=nullptr){
                cout<<"-> ";
            }
        }
        if(current==nullptr){
            cout<<"-> null"<<endl;
        }
    }
};
int main(){
    ShopEasy shop;
    shop.addProduct(1,"laptop",10000.00);
    shop.addProduct(2,"mobile",500.00);
    shop.displayProduct();
    return 0;
}