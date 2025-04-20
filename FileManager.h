#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include "Transaction.h"
using namespace std;

class FileManager {
public:
    static void saveTransaction(const Transaction& tx, const string& filename);
    static vector<Transaction> loadTransactions(const string& filename);
};

#endif