// BankAccount.cpp
#include "BankAccount.h"
#include "Transaction.h"
#include <string>
#include <list>

BankAccount::BankAccount(std::string pAccountType){
    accountType = pAccountType;
    transactions = {};
}

std::string BankAccount::getAccountType() {
    return accountType;
}

void BankAccount::setAccountType(std::string pAccountType) {
    accountType = pAccountType;
}

void BankAccount::setTransactions(std::list<Transaction> pTransactions){
    transactions = pTransactions;
}

std::list<Transaction> BankAccount::getTransactions() {
    return transactions;
}

// Calculating balances from transactions
double BankAccount::getBalance() {
    double balance = 0.0;

    if (!transactions.empty()) {
        for (Transaction transaction : transactions) {
            balance += transaction.getAmount();
        }
    }

    return balance;
}

void BankAccount::addTransaction(Transaction pTransaction){
    transactions.push_back(pTransaction);
}
