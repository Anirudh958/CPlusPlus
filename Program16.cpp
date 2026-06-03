#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Medicine Class
class Medicine {
private:
    int id;
    string name;
    string manufacturer;
    double price;
    int quantity;
    
public:
    // Constructors
    Medicine() : id(0), name(""), manufacturer(""), price(0.0), quantity(0) {}
    
    Medicine(int id, string name, string manufacturer, double price, int quantity) 
        : id(id), name(name), manufacturer(manufacturer), price(price), quantity(quantity) {}
    
    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    string getManufacturer() const { return manufacturer; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    
    // Setters
    void setQuantity(int q) { quantity = q; }
    
    // Operator Overloading for comparisons
    bool operator==(const Medicine& other) const {
        return (this->id == other.id) || (this->name == other.name);
    }
    
    bool operator!=(const Medicine& other) const {
        return !(*this == other);
    }
    
    bool operator<(const Medicine& other) const {
        return this->id < other.id;
    }
    
    bool operator>(const Medicine& other) const {
        return this->id > other.id;
    }
    
    // Assignment operator
    Medicine& operator=(const Medicine& other) {
        if (this != &other) {
            this->id = other.id;
            this->name = other.name;
            this->manufacturer = other.manufacturer;
            this->price = other.price;
            this->quantity = other.quantity;
        }
        return *this;
    }
    
    // Friend function for output stream operator overloading
    friend ostream& operator<<(ostream& os, const Medicine& m) {
        os << "[ID:" << m.id << "|" << m.name << "|" << m.manufacturer 
           << "|₹" << m.price << "|Qty:" << m.quantity << "]";
        return os;
    }
    
    // Display function
    void display() const {
        cout << *this;
    }
};

// Node Class for Linked List
class Node {
public:
    Medicine data;
    Node* next;
    
    Node() : next(nullptr) {}
    Node(Medicine med) : data(med), next(nullptr) {}
};

// Pharmacy Class with Linked List
class Pharmacy {
private:
    Node* head;
    Node* tail;  // For efficient end insertion
    string pharmacyName;
    int size;
    
public:
    // Constructor
    Pharmacy(string name) : head(nullptr), tail(nullptr), pharmacyName(name), size(0) {}
    
    // Destructor
    ~Pharmacy() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    
    // 1. Addition at the beginning (LIFO)
    void addAtBeginning(Medicine med) {
        Node* newNode = new Node(med);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;
        cout << "Added at beginning: " << med << endl;
    }
    
    // 2. Addition at the end (FIFO)
    void addAtEnd(Medicine med) {
        Node* newNode = new Node(med);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
        cout << "Added at end: " << med << endl;
    }
    
    // 3. Display all medicines
    void display() const {
        cout << "\n=== " << pharmacyName << " ===" << endl;
        if (head == nullptr) {
            cout << "Empty Pharmacy" << endl;
            return;
        }
        
        Node* current = head;
        int count = 1;
        while (current != nullptr) {
            cout << count++ << ". " << current->data << endl;
            current = current->next;
        }
        cout << "Total medicines: " << size << endl;
    }
    
    // 4. Get head node for operations
    Node* getHead() const { return head; }
    
    // 5. Get size
    int getSize() const { return size; }
    
    // 6. Get pharmacy name
    string getName() const { return pharmacyName; }
    
    // 7. Find common medicines between two pharmacies
    static vector<Medicine> findCommonMedicines(Pharmacy& p1, Pharmacy& p2) {
        vector<Medicine> common;
        Node* current1 = p1.head;
        
        while (current1 != nullptr) {
            Node* current2 = p2.head;
            while (current2 != nullptr) {
                if (current1->data == current2->data) {
                    common.push_back(current1->data);
                    break;
                }
                current2 = current2->next;
            }
            current1 = current1->next;
        }
        return common;
    }
    
    // 8. Find uncommon medicines (medicines in p1 but not in p2)
    static vector<Medicine> findUncommonMedicines(Pharmacy& p1, Pharmacy& p2) {
        vector<Medicine> uncommon;
        Node* current1 = p1.head;
        
        while (current1 != nullptr) {
            Node* current2 = p2.head;
            bool found = false;
            while (current2 != nullptr) {
                if (current1->data == current2->data) {
                    found = true;
                    break;
                }
                current2 = current2->next;
            }
            if (!found) {
                uncommon.push_back(current1->data);
            }
            current1 = current1->next;
        }
        return uncommon;
    }
    
    // 9. Merge two pharmacies (combine all medicines)
    static Pharmacy mergePharmacies(Pharmacy& p1, Pharmacy& p2, string mergedName) {
        Pharmacy merged(mergedName);
        
        // Add all medicines from first pharmacy
        Node* current = p1.head;
        while (current != nullptr) {
            merged.addAtEnd(current->data);
            current = current->next;
        }
        
        // Add all medicines from second pharmacy
        current = p2.head;
        while (current != nullptr) {
            merged.addAtEnd(current->data);
            current = current->next;
        }
        
        return merged;
    }
    
    // 10. Intersection of two pharmacies (medicines present in both)
    static Pharmacy intersection(Pharmacy& p1, Pharmacy& p2, string intersectionName) {
        Pharmacy intersection(intersectionName);
        vector<Medicine> common = findCommonMedicines(p1, p2);
        
        for (Medicine& med : common) {
            intersection.addAtEnd(med);
        }
        return intersection;
    }
    
    // 11. Union of two pharmacies (all medicines without duplicates)
    static Pharmacy unionPharmacies(Pharmacy& p1, Pharmacy& p2, string unionName) {
        Pharmacy unionPharmacy(unionName);
        
        // Add all from p1
        Node* current = p1.head;
        while (current != nullptr) {
            unionPharmacy.addAtEnd(current->data);
            current = current->next;
        }
        
        // Add from p2 only if not already present
        current = p2.head;
        while (current != nullptr) {
            Node* check = unionPharmacy.head;
            bool exists = false;
            while (check != nullptr) {
                if (check->data == current->data) {
                    exists = true;
                    break;
                }
                check = check->next;
            }
            if (!exists) {
                unionPharmacy.addAtEnd(current->data);
            }
            current = current->next;
        }
        return unionPharmacy;
    }
    
    // 12. Two-pointer approach: Find kth from end
    Medicine findKthFromEnd(int k) {
        if (head == nullptr) {
            throw runtime_error("List is empty");
        }
        
        Node* slow = head;
        Node* fast = head;
        
        // Move fast pointer k steps ahead
        for (int i = 0; i < k; i++) {
            if (fast == nullptr) {
                throw runtime_error("k is larger than list size");
            }
            fast = fast->next;
        }
        
        // Move both pointers until fast reaches end
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow->data;
    }
    
    // 13. Two-pointer approach: Find middle element
    Medicine findMiddle() {
        if (head == nullptr) {
            throw runtime_error("List is empty");
        }
        
        Node* slow = head;
        Node* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow->data;
    }
    
    // 14. Two-pointer approach: Detect cycle (if any)
    bool hasCycle() {
        if (head == nullptr) return false;
        
        Node* slow = head;
        Node* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
    
    // 15. Remove duplicates
    void removeDuplicates() {
        if (head == nullptr) return;
        
        Node* current = head;
        while (current != nullptr) {
            Node* runner = current;
            while (runner->next != nullptr) {
                if (runner->next->data == current->data) {
                    Node* duplicate = runner->next;
                    runner->next = runner->next->next;
                    delete duplicate;
                    size--;
                } else {
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    }
};

// Array-based Operations Class
class ArrayPharmacy {
private:
    vector<Medicine> medicines;
    string pharmacyName;
    
public:
    ArrayPharmacy(string name) : pharmacyName(name) {}
    
    void addMedicine(Medicine med) {
        medicines.push_back(med);
    }
    
    void display() const {
        cout << "\n=== " << pharmacyName << " (Array Implementation) ===" << endl;
        for (size_t i = 0; i < medicines.size(); i++) {
            cout << i+1 << ". " << medicines[i] << endl;
        }
    }
    
    // Find common medicines using arrays
    static vector<Medicine> findCommonMedicines(ArrayPharmacy& p1, ArrayPharmacy& p2) {
        vector<Medicine> common;
        for (Medicine& m1 : p1.medicines) {
            for (Medicine& m2 : p2.medicines) {
                if (m1 == m2) {
                    common.push_back(m1);
                    break;
                }
            }
        }
        return common;
    }
    
    // Merge two arrays
    static ArrayPharmacy mergePharmacies(ArrayPharmacy& p1, ArrayPharmacy& p2, string mergedName) {
        ArrayPharmacy merged(mergedName);
        for (Medicine& m : p1.medicines) {
            merged.addMedicine(m);
        }
        for (Medicine& m : p2.medicines) {
            merged.addMedicine(m);
        }
        return merged;
    }
};

// Main function to demonstrate all operations
int main() {
    cout << "╔══════════════════════════════════════════════════════════════╗" << endl;
    cout << "║          PHARMACY MANAGEMENT SYSTEM - LINKED LIST           ║" << endl;
    cout << "╚══════════════════════════════════════════════════════════════╝" << endl;
    
    // Create two pharmacies
    Pharmacy pharmacy1("Apollo Pharmacy");
    Pharmacy pharmacy2("MedPlus Pharmacy");
    
    cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    cout << "1. ADDING MEDICINES TO PHARMACIES" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    
    // Adding to Pharmacy 1 (Mix of beginning and end)
    pharmacy1.addAtEnd(Medicine(101, "Paracetamol", "Cipla", 25.50, 100));
    pharmacy1.addAtEnd(Medicine(102, "Aspirin", "Bayer", 15.75, 200));
    pharmacy1.addAtBeginning(Medicine(103, "Amoxicillin", "GSK", 85.00, 50));
    pharmacy1.addAtEnd(Medicine(104, "Vitamin C", "Abbott", 45.00, 150));
    
    // Adding to Pharmacy 2
    pharmacy2.addAtEnd(Medicine(101, "Paracetamol", "Cipla", 25.50, 80));
    pharmacy2.addAtBeginning(Medicine(105, "Ibuprofen", "Pfizer", 35.00, 120));
    pharmacy2.addAtEnd(Medicine(106, "Cetirizine", "Sun Pharma", 12.50, 300));
    pharmacy2.addAtEnd(Medicine(102, "Aspirin", "Bayer", 15.75, 180));
    
    // Display both pharmacies
    pharmacy1.display();
    pharmacy2.display();
    
    cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    cout << "2. TWO-POINTER APPROACH DEMONSTRATION" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    
    try {
        cout << "\nPharmacy 1 Medicines:" << endl;
        pharmacy1.display();
        
        cout << "\nTwo-Pointer Operations:" << endl;
        cout << "• Middle element: " << pharmacy1.findMiddle() << endl;
        cout << "• 2nd element from end: " << pharmacy1.findKthFromEnd(2) << endl;
        cout << "• Does list have cycle? " << (pharmacy1.hasCycle() ? "Yes" : "No") << endl;
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    cout << "3. LINKED LIST OPERATIONS (COMMON, UNCOMMON, INTERSECTION)" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    
    // Find common medicines
    vector<Medicine> common = Pharmacy::findCommonMedicines(pharmacy1, pharmacy2);
    cout << "\n✓ Common Medicines in both pharmacies:" << endl;
    if (common.empty()) {
        cout << "  No common medicines found" << endl;
    } else {
        for (Medicine& m : common) {
            cout << "  • " << m << endl;
        }
    }
    
    // Find uncommon medicines (in pharmacy1 but not in pharmacy2)
    vector<Medicine> uncommon = Pharmacy::findUncommonMedicines(pharmacy1, pharmacy2);
    cout << "\n✓ Medicines only in " << pharmacy1.getName() << ":" << endl;
    for (Medicine& m : uncommon) {
        cout << "  • " << m << endl;
    }
    
    // Intersection
    Pharmacy intersection = Pharmacy::intersection(pharmacy1, pharmacy2, "Common Medicines");
    intersection.display();
    
    // Union
    Pharmacy unionPharmacy = Pharmacy::unionPharmacies(pharmacy1, pharmacy2, "Combined Pharmacy");
    unionPharmacy.display();
    
    cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    cout << "4. MERGE OPERATIONS" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    
    Pharmacy merged = Pharmacy::mergePharmacies(pharmacy1, pharmacy2, "Mega Pharmacy");
    merged.display();
    
    cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    cout << "5. ARRAY-BASED IMPLEMENTATION" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    
    ArrayPharmacy arrayPharm1("City Pharmacy");
    ArrayPharmacy arrayPharm2("Town Pharmacy");
    
    arrayPharm1.addMedicine(Medicine(201, "Paracetamol", "Cipla", 26.00, 90));
    arrayPharm1.addMedicine(Medicine(202, "Antibiotic", "GSK", 95.00, 45));
    arrayPharm2.addMedicine(Medicine(201, "Paracetamol", "Cipla", 26.00, 70));
    arrayPharm2.addMedicine(Medicine(203, "Antihistamine", "Sun", 18.00, 110));
    
    arrayPharm1.display();
    arrayPharm2.display();
    
    vector<Medicine> arrayCommon = ArrayPharmacy::findCommonMedicines(arrayPharm1, arrayPharm2);
    cout << "\nCommon medicines (Array implementation):" << endl;
    for (Medicine& m : arrayCommon) {
        cout << "  • " << m << endl;
    }
    
    cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    cout << "6. OPERATOR OVERLOADING DEMONSTRATION" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    
    Medicine med1(301, "Crocin", "GSK", 28.50, 200);
    Medicine med2(301, "Crocin", "GSK", 28.50, 200);
    Medicine med3(302, "Dolo", "Micro Labs", 32.00, 150);
    
    cout << "Medicine 1: " << med1 << endl;
    cout << "Medicine 2: " << med2 << endl;
    cout << "Medicine 3: " << med3 << endl;
    
    cout << "\nOperator Overloading Results:" << endl;
    cout << "med1 == med2: " << (med1 == med2 ? "true" : "false") << endl;
    cout << "med1 == med3: " << (med1 == med3 ? "true" : "false") << endl;
    cout << "med1 != med3: " << (med1 != med3 ? "true" : "false") << endl;
    cout << "med1 < med3: " << (med1 < med3 ? "true" : "false") << endl;
    cout << "med1 > med3: " << (med1 > med3 ? "true" : "false") << endl;
    
    cout << "\n╔══════════════════════════════════════════════════════════════╗" << endl;
    cout << "║                    PROGRAM COMPLETED                         ║" << endl;
    cout << "╚══════════════════════════════════════════════════════════════╝" << endl;
    
    return 0;
}