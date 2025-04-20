#include "Wallet.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

Wallet::Wallet() {
    mockPrices = {
        {"BTC", 30000},
        {"ETH", 2000},
        {"DOGE", 0.08}
    };
}

void Wallet::loadData() {
    transactions = FileManager::loadTransactions("transactions.csv");
    for (auto& tx : transactions) {
        if (tx.type == "buy") {
            holdings[tx.token] += tx.quantity;
            investments[tx.token] += tx.quantity * tx.pricePerUnit;
        }
        else if (tx.type == "sell") {
            holdings[tx.token] -= tx.quantity;
        }
    }
}

void Wallet::addTransaction() {
    Transaction tx;
    cout << "Enter transaction type (buy/sell): "; cin >> tx.type;
    cout << "Enter token (BTC/ETH/DOGE): "; cin >> tx.token;
    cout << "Enter quantity: "; cin >> tx.quantity;
    cout << "Enter price per unit: "; cin >> tx.pricePerUnit;
    cout << "Enter date (DD-MM-YYYY): "; cin >> tx.date;

    transactions.push_back(tx);
    if (tx.type == "buy") {
        holdings[tx.token] += tx.quantity;
        investments[tx.token] += tx.quantity * tx.pricePerUnit;
    } else if (tx.type == "sell") {
        holdings[tx.token] -= tx.quantity;
    }

    FileManager::saveTransaction(tx, "transactions.csv");
    cout << "Transaction added successfully!\n";
}

void Wallet::viewPortfolio() {
    cout << fixed << setprecision(2);
    cout << "\n--- Portfolio Summary ---\n";
    for (auto& pair : holdings) {
        double qty = pair.second;
        double currentValue = qty * mockPrices[pair.first];
        double invested = investments[pair.first];
        double profitLoss = currentValue - invested;
        double percent = (invested > 0) ? (profitLoss / invested) * 100 : 0;
        cout << pair.first << ": " << qty << " units | Value: $" << currentValue << " | Invested: $" << invested
             << " | P/L: $" << profitLoss << " (" << percent << "%)\n";
    }
}

void Wallet::viewHistory(bool sorted) {
    if (sorted) {
        sort(transactions.begin(), transactions.end(), [](const Transaction& a, const Transaction& b) {
            return a.date < b.date;
        });
    }

    cout << "\n--- Transaction History ---\n";
    for (auto& tx : transactions) {
        cout << tx.date << " - " << tx.type << " " << tx.quantity << " " << tx.token << " at $" << tx.pricePerUnit << "\n";
    }
}

void Wallet::displayBarChart() {
    cout << "\n--- ASCII Bar Chart of Portfolio ---\n";
    for (auto& pair : holdings) {
        int barLength = static_cast<int>(pair.second * mockPrices[pair.first] / 100);
        cout << pair.first << " | ";
        for (int i = 0; i < barLength; ++i) cout << "#";
        cout << " $" << pair.second * mockPrices[pair.first] << "\n";
    }
}

bool login() {
    string storedUsername = "admin";
    string storedPassword = "pass123";

    string username, password;
    cout << "\n=== Login Required ===\n";
    cout << "Username: "; cin >> username;
    cout << "Password: "; cin >> password;

    return username == storedUsername && password == storedPassword;
}