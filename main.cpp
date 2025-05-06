#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Customer {
private:
    int customerID;               
    string name;                  
    string phone;                 
    vector<pair<int, int>> cart;
public:
    // Constructor
    Customer(int id, const string& name, const string& phone)
        : customerID(id) {
        setName(name);
        setPhone(phone);
    }

    // Destructor
    ~Customer() {
        cart.clear();
    }

    // Getters
    int getCustomerID() const { return customerID; }
    string getName() const { return name; }
    string getPhone() const { return phone; }

    // Setters
    void setName(const string& newName) {
        if (newName.empty()) {
            cout << "Error: Name cannot be empty.\n";
            return;
        }
        for (char ch : newName) {
            if (!isalpha(ch) && ch != ' ' && ch != '-') {
                cout << "Error: Name contains invalid characters.\n";
                return;
            }
        }
        name = newName;
    }

    void setPhone(const string& newPhone) {
        if (newPhone.length() < 7 || newPhone.length() > 15) {
            cout << "Error: Phone number must be between 7 and 15 digits.\n";
            return;
        }

        for (char ch : newPhone) {
            if (!isdigit(ch)) {
                cout << "Error: Phone number must contain only digits.\n";
                return;
            }
        }

        phone = newPhone;
    }

    // Add item to cart
    void addToCart(int productID, int quantity) {
        if (productID < 0 || quantity <= 0) {
            cout << "Error: Invalid product ID or quantity.\n";
            return;
        }

        for (auto& item : cart) {
            if (item.first == productID) {
                item.second += quantity;
                return;
            }
        }

        cart.push_back({productID, quantity});
    }

    // Remove item from cart
    void removeFromCart(int productID) {
        for (auto it = cart.begin(); it != cart.end(); ++it) {
            if (it->first == productID) {
                cart.erase(it);
                return;
            }
        }

        cout << "Error: Product not found in cart.\n";
    }

    // Show cart contents
    void showCart() const {
        if (cart.empty()) {
            cout << "Cart is empty.\n";
            return;
        }

        cout << "Cart contents:\n";
        for (const auto& item : cart) {
            cout << " - Product ID: " << item.first << ", Quantity: " << item.second << "\n";
        }
    }

    // Clear the cart
    void clearCart() {
        cart.clear();
        cout << "Cart cleared successfully.\n";
    }

    // Get the cart (for invoice)
    vector<pair<int, int>> getCart() const {
        return cart;
    }
};



int main() {
 
    return 0;
}