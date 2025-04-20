#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
using namespace std;

struct Transaction {
    string type;
    string token;
    double quantity;
    double pricePerUnit;
    string date;

    string toCSV() const;
    static Transaction fromCSV(const string& line);
};

#endif