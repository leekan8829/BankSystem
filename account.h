#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <string>
#include <vector>

using namespace std;

class Account
{
public:
    Account();
    Account(string id, string name, double balance);
    string id;
    string name;
    double balance;
    void printAcct();
};

void savemoney(Account &acct, double amount);
void takemoney(Account &acct, double amount);
void listallAcct(vector<Account> &customer);
void createAcct(vector<Account> &customer);
void deposit(vector<Account> &customer);
void withdraw(vector<Account> &customer);
int menu(vector<Account> &acct_vect);

#endif