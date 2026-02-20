#include<iostream>
// #include "Medicine.h"
#include <string>

using namespace std;


class Medicine {
private:
    string name;
    double price;
    int quantity;
    string expiryDate;
    
public:

Medicine(string n, double p, int q, string exp) {
        name = n;
        price = p;
        quantity = q;
        expiryDate = exp;
        cout << "Medicine created: " << name << endl;
    }
// Medicine(Medicine& j)
// {
//     this->expiryDate = j.expiryDate;
//     this->name = j.name;
// }

Medicine(int i):quantity(i)
{

}
// you have other constructors
    Medicine() {
        name = "Unknown";
        price = 0.0;
        quantity = 0;
        expiryDate = "N/A";
    }
    
        ~Medicine() {
        cout << "Medicine destroyed: " << name << endl;
    }
    
    // GETTER METHODS (Accessors) - Same as Java
    string getName() {
        return name;
    }
    
    double getPrice() {
        return price;
    }
    
    int getQuantity() {
        return quantity;
    }
    
    string getExpiryDate() {
        return expiryDate;
    }
    
    // SETTER METHODS (Mutators) - Same as Java
    void setPrice(double p) {
        if (p >= 0) {
            price = p;
        }
    }
    
    void setQuantity(int q) {
        if (q >= 0) {
            quantity = q;
        }
    }
    
    void sell(int amount) {
        if (amount <= quantity) {
            quantity -= amount;
            cout << "Sold " << amount << " units of " << name << endl;
            cout << "Remaining quantity: " << quantity << endl;
        } else {
            cout << "Insufficient stock! Only " << quantity << " available." << endl;
        }
    }
    
    void restock(int amount) {
        quantity += amount;
        cout << "Restocked " << amount << " units of " << name << endl;
    }
    
    double calculateTotal(int amount) {
        return price * amount;
    }
    
    // Display method - like toString() in Java
    void display() {
        cout << "\n--- Medicine Details ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Expiry: " << expiryDate << endl;
    }
    
    
    void displayConst() const {
        cout << name << " - $" << price << endl;
        // price = 100; // ERROR! Can't modify in const method
    }
    

};



class Pharmacy {
private:
    string pharmacyName;
    string address;
    Medicine inventory[3];  
    
public:
     Pharmacy(string name, string addr, Medicine m1,Medicine m2,Medicine m3) : pharmacyName(name), address(addr) {
        inventory[0] = m1;
        inventory[1] = m2;
        inventory[2] = m3;
cout << "\nPharmacy '" << pharmacyName << "' opened!" << endl;
    }
        
    ~Pharmacy() {
        cout << "\nPharmacy '" << pharmacyName << "' closing..." << endl;
    }
    
    void displayInfo() {
        cout << "\n========== PHARMACY INFO ==========" << endl;
        cout << "Name: " << pharmacyName << endl;
        cout << "Address: " << address << endl;
    }
        Medicine getCheapestDrug(){
        double  min = inventory[0].getPrice();
        Medicine m ;
        for(size_t i=0;i<3;i++){
            if(min>inventory[i].getPrice()){
                min = inventory[i].getPrice();
                m=inventory[i];
            }
        }
        
        return m;
    }
};





int main() {
    
        
    void printMedicine(Medicine m);
    
    void updatePrice(Medicine& m, double newPrice);
    
     void checkStock(Medicine* m);
      
      
    cout << "=== C++ PHARMACY MANAGEMENT SYSTEM ===" << endl;
    
//     cout << "\n--- Creating Medicine on STACK ---" << endl;
//     Medicine aspirin("Aspirin", 5.99, 100, "2026-12-31");
       
//     aspirin.display();
//     aspirin.sell(20);
    
//     cout << "\n--- Creating Medicine on HEAP ---" << endl;
//     Medicine* paracetamol = new Medicine("Paracetamol", 3.50, 200, "2027-06-15");
        
//     paracetamol->display();
//     paracetamol->sell(50);
//     paracetamol->restock(100);
    
//   cout << "\n--- Creating Multiple Medicines ---" << endl;
//     Medicine med1("Ibuprofen", 7.25, 150, "2026-08-20");
//     Medicine med2("Cough Syrup", 12.99, 75, "2025-11-30");
//     Medicine med3;  
    
//     cout << "\n--- Copying Objects ---" << endl;
//     Medicine copy = aspirin;         
//     copy.setPrice(8.99);
//     cout << "Original price: $" << aspirin.getPrice() << endl;
//     cout << "Copy price: $" << copy.getPrice() << endl;
//     cout << "\n--- Function Call Examples ---" << endl;

    
//     updatePrice(med1, 9.99);
//     checkStock(paracetamol);
//           cout << "\n--- Array of Medicines ---" << endl;
//     Medicine medicines[3];  
//     medicines[0] = Medicine("Vitamin C", 15.00, 50, "2027-01-01");
//     medicines[1] = Medicine("Antibiotic", 25.50, 30, "2026-03-15");
//     medicines[2] = Medicine("Pain Relief", 8.75, 120, "2026-09-10");
    
//     for (int i = 0; i < 3; i++) {
//         medicines[i].display();
//     }
    
//         cout << "\n--- Creating Pharmacy ---" << endl;
//     Pharmacy cityPharmacy("City Health Pharmacy", "123 Main Street");
//     cityPharmacy.displayInfo();
    
    
//     cout << "\n--- Demonstrating 'this' pointer ---" << endl;
//     cout << "Address of aspirin object: " << &aspirin << endl;
      
//       cout << "\n--- Manual Memory Management ---" << endl;
//     delete paracetamol;  
    
//     paracetamol = nullptr;  
    
//     cout << "\n--- Program Ending (Stack objects auto-destroyed) ---" << endl;
//     // Stack objects (aspirin, med1, med2, etc.) 
    
    

    
    cout << "\n--- Array of Medicines ---" << endl;
    Medicine m1("Vitamin C", 15.00, 50, "2027-01-01");
    Medicine m2("Antibiotic", 25.50, 30, "2026-03-15");
    Medicine m3("Pain Relief", 8.75, 120, "2026-09-10");
    
        Pharmacy ShopPharmacy("ShopPharmacy", "HYD Main Street Narayanguda",m1,m2,m3);
    ShopPharmacy.displayInfo();

    
    Medicine m = ShopPharmacy.getCheapestDrug();
    printMedicine(m);
    return 0;
}


//Helper Functions 
void printMedicine(Medicine m) {
        m.display();
}

void updatePrice(Medicine& m, double newPrice) {
    m.setPrice(newPrice);
    cout << "Price updated to: $" << m.getPrice() << endl;
}

void checkStock(Medicine* m) {
     if (m != nullptr) {
        cout << "Checking stock for: " << m->getName() << endl;
        cout << "Available: " << m->getQuantity() << " units" << endl;
    }
}

