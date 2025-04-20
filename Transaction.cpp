#include "Transaction.h"
#include <sstream>

string Transaction::toCSV() const {
    stringstream ss;
    ss << type << "," << token << "," << quantity << "," << pricePerUnit << "," << date;
    return ss.str();
}

Transaction Transaction::fromCSV(const string& line) {
    Transaction tx;
    stringstream ss(line);
    getline(ss, tx.type, ',');
    getline(ss, tx.token, ',');
    ss >> tx.quantity; ss.ignore();
    ss >> tx.pricePerUnit; ss.ignore();
    getline(ss, tx.date);
    return tx;
}