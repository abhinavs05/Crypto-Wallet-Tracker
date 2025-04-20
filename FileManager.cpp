#include "FileManager.h"
#include <fstream>

void FileManager::saveTransaction(const Transaction& tx, const string& filename) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << tx.toCSV() << "\n";
        file.close();
    }
}

vector<Transaction> FileManager::loadTransactions(const string& filename) {
    vector<Transaction> transactions;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        transactions.push_back(Transaction::fromCSV(line));
    }
    file.close();
    return transactions;
}