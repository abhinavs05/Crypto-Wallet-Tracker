#ifndef WALLET_H
#define WALLET_H

#include <vector>
#include <map>
#include "Transaction.h"
#include "FileManager.h"

class Wallet {
private:
    std::map<std::string, double> holdings;
    std::map<std::string, double> investments;
    std::map<std::string, double> mockPrices;
    std::vector<Transaction> transactions;

public:
    Wallet();
    void loadData();
    void addTransaction();
    void viewPortfolio();
    void viewHistory(bool sorted = false);
    void displayBarChart();
};

bool login();

#endif