#include <iostream>
#include <vector>
using namespace std;

/* ================= PRODUCT ================= */
class Product {
public:
    string name;
    double price;
    int quantity;

    Product(string n, double p, int q) {
        name = n;
        price = p;
        quantity = q;
    }
};

/* ================= INVENTORY ================= */
class Inventory {
private:
    vector<Product> products;

public:
    void addProduct(Product p) {
        products.push_back(p);
    }

    void showProducts() {
        cout << "\nAvailable Products:\n";
        for (auto &p : products) {
            cout << p.name << " | Price: " << p.price 
                 << " | Quantity: " << p.quantity << endl;
        }
    }

    Product* getProduct(string name) {
        for (auto &p : products) {
            if (p.name == name) return &p;
        }
        return nullptr;
    }
};

/* ================= STRATEGY PATTERN ================= */
class PricingStrategy {
public:
    virtual double calculatePrice(Product *p) = 0;
};

class StandardPricing : public PricingStrategy {
public:
    double calculatePrice(Product *p) override {
        cout << "Using STANDARD pricing\n";
        return p->price;
    }
};

class EmergencyPricing : public PricingStrategy {
public:
    double calculatePrice(Product *p) override {
        cout << "Using EMERGENCY pricing (1.5x)\n";
        return p->price * 1.5;
    }
};

/* ================= STATE PATTERN ================= */
class KioskState {
public:
    virtual bool allowPurchase() = 0;
};

class ActiveState : public KioskState {
public:
    bool allowPurchase() override {
        cout << "Kiosk is in ACTIVE mode\n";
        return true;
    }
};

class EmergencyState : public KioskState {
public:
    bool allowPurchase() override {
        cout << "Kiosk is in EMERGENCY mode (restricted)\n";
        return false;
    }
};

/* ================= PAYMENT ================= */
class Payment {
public:
    bool processPayment(double amount) {
        cout << "Processing payment of " << amount << "...\n";
        cout << "Payment Successful!\n";
        return true;
    }
};

/* ================= COMMAND PATTERN ================= */
class Command {
public:
    virtual void execute() = 0;
};

class Kiosk; // forward declaration

class PurchaseCommand : public Command {
private:
    Kiosk *kiosk;
    string productName;

public:
    PurchaseCommand(Kiosk *k, string name) {
        kiosk = k;
        productName = name;
    }

    void execute() override;
};

/* ================= KIOSK ================= */
class Kiosk {
private:
    Inventory inventory;
    PricingStrategy *pricingStrategy;
    KioskState *state;
    Payment payment;

public:
    Kiosk(PricingStrategy *ps, KioskState *st) {
        pricingStrategy = ps;
        state = st;
    }

    void addProduct(Product p) {
        inventory.addProduct(p);
    }

    void showProducts() {
        inventory.showProducts();
    }

    void setPricingStrategy(PricingStrategy *ps) {
        pricingStrategy = ps;
    }

    void setState(KioskState *st) {
        state = st;
    }

    void purchase(string productName) {
        if (!state->allowPurchase()) {
            cout << "Purchase not allowed!\n";
            return;
        }

        Product *p = inventory.getProduct(productName);

        if (p == nullptr || p->quantity == 0) {
            cout << "Product not available!\n";
            return;
        }

        double finalPrice = pricingStrategy->calculatePrice(p);

        cout << "Final Price: " << finalPrice << endl;

        if (payment.processPayment(finalPrice)) {
            p->quantity--;
            cout << "Item dispensed successfully!\n";
        }
    }
};

/* COMMAND EXECUTION */
void PurchaseCommand::execute() {
    kiosk->purchase(productName);
}

/* ================= MAIN (INTERACTIVE) ================= */
int main() {

    PricingStrategy *standard = new StandardPricing();
    PricingStrategy *emergency = new EmergencyPricing();

    KioskState *active = new ActiveState();
    KioskState *emergencyState = new EmergencyState();

    Kiosk kiosk(standard, active);

    // Add products
    kiosk.addProduct(Product("Water", 100, 5));
    kiosk.addProduct(Product("Snacks", 50, 3));

    int choice;
    string productName;

    while (true) {
        cout << "\n===== KIOSK MENU =====\n";
        cout << "1. Show Products\n";
        cout << "2. Buy Product\n";
        cout << "3. Set Active Mode\n";
        cout << "4. Set Emergency Mode\n";
        cout << "5. Use Standard Pricing\n";
        cout << "6. Use Emergency Pricing\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                kiosk.showProducts();
                break;

            case 2:
                cout << "Enter product name: ";
                cin >> productName;
                {
                    PurchaseCommand cmd(&kiosk, productName);
                    cmd.execute();
                }
                break;

            case 3:
                kiosk.setState(active);
                cout << "Switched to ACTIVE mode\n";
                break;

            case 4:
                kiosk.setState(emergencyState);
                cout << "Switched to EMERGENCY mode\n";
                break;

            case 5:
                kiosk.setPricingStrategy(standard);
                cout << "Using STANDARD pricing\n";
                break;

            case 6:
                kiosk.setPricingStrategy(emergency);
                cout << "Using EMERGENCY pricing\n";
                break;

            case 0:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}