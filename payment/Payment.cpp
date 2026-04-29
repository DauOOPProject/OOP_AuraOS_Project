#include "Payment.h"
#include <iostream>
using namespace std;

bool Payment::processPayment(double amount, User& user) {

    cout << "Processing payment: " << amount << endl;

    if (user.deduct(amount)) {
        cout << "Payment Successful!\n";
        return true;
    } else {
        cout << "Insufficient Balance!\n";
        return false;
    }
}