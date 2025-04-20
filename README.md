# 💰 Crypto Wallet Tracker (C++ Project)

A command-line portfolio management system built in **C++** to simulate and track cryptocurrency investments like BTC, ETH, and DOGE. This app allows users to **log transactions, view profit/loss, display portfolio summaries**, and visualize their investments through ASCII charts. Includes a simple **login system** for access control.

---

## 🚀 Features

- 🔐 Secure login (username + password)
- 💹 Add buy/sell transactions for crypto tokens
- 📊 View real-time (mocked) portfolio values
- 📈 Calculate profit/loss with percentage gain/loss
- 🗃 View full or sorted transaction history
- 🖥 Console-based ASCII bar chart for holdings
- 📁 Persistent storage using CSV file handling
- 🧱 Modular structure using OOP principles

---

## 📂 File Structure

```
CryptoWalletTracker/
│
├── main.cpp             # Entry point with menu and login
├── Wallet.h / Wallet.cpp         # Main logic for portfolio management
├── Transaction.h / Transaction.cpp   # Struct and logic for transaction records
├── FileManager.h / FileManager.cpp   # Handles file I/O (save/load)
└── transactions.csv     # Auto-created CSV file to store user transactions
```

---

## 🧑‍💻 How to Run

1. **Compile the project**
```bash
g++ main.cpp Wallet.cpp Transaction.cpp FileManager.cpp -o CryptoWalletTracker
```

2. **Run the application**
```bash
./CryptoWalletTracker
```

> 🧠 Default credentials: `admin` / `pass123`

---

## 📝 Sample Transaction Input

```text
Transaction type: buy
Token: BTC
Quantity: 0.05
Price per unit: 29000
Date: 15-04-2025
```

---

## 📊 Sample Portfolio Output

```text
BTC: 0.05 units | Value: $1500.00 | Invested: $1450.00 | P/L: $50.00 (+3.45%)
ETH: 0.75 units | Value: $1500.00 | Invested: $1425.00 | P/L: $75.00 (+5.26%)
```

---

## 🛡️ Future Enhancements

- Password encryption
- Multi-user support
- Real-time price fetch via APIs
- GUI version using Qt or web interface

---

## 📃 License

This project is for educational and portfolio use. Free to fork and modify.