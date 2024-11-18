#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
    int productID;
    string name;
    float price;

public:
    Product(int id, string n, float p) : productID(id), name(n), price(p) {}

    virtual void displayProductDetails() const {
        cout << "Product ID: " << productID << endl;
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
    }

    virtual ~Product() {}
};

class Electronics : public Product {
private:
    int warrantyPeriod;

public:
    Electronics(int id, string n, float p, int warranty) : Product(id, n, p), warrantyPeriod(warranty) {}

    void displayProductDetails() const override {
        Product::displayProductDetails();
        cout << "Warranty Period: " << warrantyPeriod << " years" << endl;
    }
};

class Furniture : public Product {
private:
    string materialType;

public:
    Furniture(int id, string n, float p, string material) : Product(id, n, p), materialType(material) {}

   void displayProductDetails() const override {
        Product::displayProductDetails();
        cout << "Material Type: " << materialType << endl;
    }
};

int main() {
   
    Product* inventory[4];

  
    inventory[0] = new Electronics(101, "Smartphone", 600, 2);
    inventory[1] = new Furniture(202, "Dining Table", 700, "Wood");

    for (int i = 0; i < 4; ++i) {
        cout << "\nProduct Details: \n";
        inventory[i]->displayProductDetails();
        cout << endl;
    }

    for (int i = 0; i < 4; ++i) {
           delete inventory[i];
    }

    return 0;
}