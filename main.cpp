#include <iostream>
using namespace std;

#include "command/PurchaseCommand.h"
#include "core/Kiosk.h"
#include "factory/KioskFactory.h"
#include "failure/AlertHandler.h"
#include "failure/RecalibrationHandler.h"
#include "failure/RetryHandler.h"
#include "inventory/FileManager.h"
#include "inventory/TransactionManager.h"
#include "models/Product.h"
#include "models/UserManager.h"  // 🔥 NEW
#include "observer/EventManager.h"
#include "observer/MonitoringSystem.h"
#include "pricing/EmergencyPricing.h"
#include "pricing/StandardPricing.h"
#include "registry/CentralRegistry.h"
#include "registry/SystemConfig.h"
#include "state/ActiveState.h"
#include "state/EmergencyState.h"
#include "state/MaintenanceState.h"
#include "state/PowerSavingState.h"

int main() {
  cout << "===== Aura Retail OS Started =====\n";

  CentralRegistry::getInstance()->showSystemInfo();

  Kiosk* kiosk = KioskFactory::createKiosk("Pharmacy");

  /* LOAD INVENTORY */
  kiosk->getInventory().setProducts(FileManager::load());

  if (kiosk->getInventory().getAllProducts().empty()) {
    kiosk->addProduct(Product("Water", 100, 5));
    kiosk->addProduct(Product("Snacks", 50, 3));
    FileManager::save(kiosk->getInventory().getAllProducts());
  }

  /* 🔥 LOAD USER */
  User user = UserManager::load();

  /* LOAD CONFIG */
  auto config = SystemConfig::load();

  KioskState* active = new ActiveState();
  KioskState* emergency = new EmergencyState();
  KioskState* maintenance = new MaintenanceState();
  KioskState* power = new PowerSavingState();

  PricingStrategy* standard = new StandardPricing();
  PricingStrategy* emergencyPricing = new EmergencyPricing();

  if (config.first == "Maintenance")
    kiosk->setState(maintenance);
  else if (config.first == "Emergency")
    kiosk->setState(emergency);
  else if (config.first == "Power")
    kiosk->setState(power);
  else
    kiosk->setState(active);

  if (config.second == "Emergency")
    kiosk->setPricingStrategy(emergencyPricing);
  else
    kiosk->setPricingStrategy(standard);

  /* OBSERVER */
  EventManager em;
  MonitoringSystem ms;
  em.subscribe(&ms);
  kiosk->setEventManager(&em);

  /* FAILURE */
  RetryHandler r;
  RecalibrationHandler rc;
  AlertHandler a;

  r.setNext(&rc);
  rc.setNext(&a);

  int choice;

  while (true) {
    cout << "\n===== MENU =====\n";
    cout << "1. Show Products\n";
    cout << "2. Buy Product\n";
    cout << "3. Add Product\n";
    cout << "4. Active Mode\n";
    cout << "5. Emergency Mode\n";
    cout << "6. Maintenance Mode\n";
    cout << "7. Power Saving Mode\n";
    cout << "8. Standard Pricing\n";
    cout << "9. Emergency Pricing\n";
    cout << "10. Trigger Failure\n";
    cout << "11. Show Transactions\n";
    cout << "12. Show Balance\n";
    cout << "13. Add Balance\n";
    cout << "0. Exit\n";

    cout << "Enter your choice : ";
    cin >> choice;

    switch (choice) {
      case 1:
        kiosk->showProducts();
        break;

      case 2: {
        string name;
        int qty;

        cout << "Enter product: ";
        cin >> name;

        cout << "Enter quantity: ";
        cin >> qty;

        PurchaseCommand cmd(kiosk, name, user, qty);
        cmd.execute();

        user.showBalance();

        FileManager::save(kiosk->getInventory().getAllProducts());
        UserManager::save(user);

        break;
      }

      case 3: {
        string name;
        double price;
        int qty;

        cout << "Name: ";
        cin >> name;
        cout << "Price: ";
        cin >> price;
        cout << "Quantity: ";
        cin >> qty;

        kiosk->addProduct(Product(name, price, qty));
        FileManager::save(kiosk->getInventory().getAllProducts());
        break;
      }

      case 4:
        kiosk->setState(active);
        kiosk->setPricingStrategy(standard);
        SystemConfig::save("Active", "Standard");
        cout<<"Active Mode Activated"<<endl;
        break;

      case 5:
        kiosk->setState(emergency);
        kiosk->setPricingStrategy(emergencyPricing);
        SystemConfig::save("Emergency", "Emergency");
        cout<<"Emergency Mode Activated"<<endl;
        break;

      case 6:
        kiosk->setState(maintenance);
        kiosk->setPricingStrategy(standard);
        SystemConfig::save("Maintenance", "Standard");
        cout<<"Maintenance Mode Activated"<<endl;
        break;

      case 7:
        kiosk->setState(power);
        kiosk->setPricingStrategy(standard);
        SystemConfig::save("Power", "Standard");
        cout<<"Power Saving Mode Activated"<<endl;
        break;

      case 8:
        kiosk->setPricingStrategy(standard);
        SystemConfig::save("Active", "Standard");
        cout<<"Standard Pricing Activated"<<endl;
        break;

      case 9:
        kiosk->setPricingStrategy(emergencyPricing);
        SystemConfig::save("Active", "Emergency");
        cout<<"Emergency Pricing Activated"<<endl;
        break;

      case 10:
        r.handle();
        break;

      case 11:
        TransactionManager::showHistory();
        break;

      case 12:
        user.showBalance();
        break;

      case 13: {
        double amount;
        cout << "Enter amount to add: ";
        cin >> amount;

        if (amount <= 0) {
          cout << "Invalid amount!\n";
          break;
        }

        user.addBalance(amount);

        cout << "Balance added successfully!\n";

        user.showBalance();

        UserManager::save(user);  // 🔥 VERY IMPORTANT (persistence)

        break;
      }

      case 0:
        return 0;
    }
  }
}