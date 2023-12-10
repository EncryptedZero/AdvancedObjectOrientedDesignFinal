// Transaction.cpp
#include "Transaction.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <iostream>

Transaction::Transaction(double pAmount, std::string pMemo)
{
    amount = pAmount;
    memo = pMemo;

    // Get the current time
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    // Format the time as a string
    std::stringstream ss;
    ss << std::put_time(std::localtime(&now), "%F %T");
    date = ss.str();
}

Transaction::Transaction(Transaction& t)
{
    Transaction(t.getAmount(), t.getMemo());
}

// Getter and setter for 'amount'
double Transaction::getAmount() {
    return amount;
}

void Transaction::setAmount(double pAmount) {
    amount = pAmount;
}

// Getter and setter for 'date'
std::string Transaction::getDate() {
    return date;
}

// Getter and setter for 'memo'
std::string Transaction::getMemo() {
    return memo;
}

void Transaction::setMemo(std::string pMemo) {
    memo = pMemo;
}

void Transaction::printTransactionDetails()
{
    std::cout << "Transaction Details: " << std::endl;
    if (amount < 0) {
        std::cout << "Withdrawal: " << -amount << std::endl;
    }
    else {
        std::cout << "Deposit: " << amount << std::endl;
    }
    std::cout << "Date: " << date << std::endl;
    std::cout << "Memo: " << memo << std::endl;
}
