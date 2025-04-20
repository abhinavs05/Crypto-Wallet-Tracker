#include "Wallet.h"
#include <iostream>
using namespace std;

int main() {
    if (!login()) {
        cout << "\nAccess denied. Invalid credentials.\n";
        return 1;
    }

    Wallet wallet;
    wallet.loadData();
    int choice;
    do {
        cout << "\n=== Crypto Wallet Tracker ===\n";
        cout << "1. Add Transaction\n2. View Portfolio\n3. View Transaction History\n4. View Sorted Transaction History\n5. Show ASCII Bar Chart\n0. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: wallet.addTransaction(); break;
            case 2: wallet.viewPortfolio(); break;
            case 3: wallet.viewHistory(false); break;
            case 4: wallet.viewHistory(true); break;
            case 5: wallet.displayBarChart(); break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
    return 0;
}