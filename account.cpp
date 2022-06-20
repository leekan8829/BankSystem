#include <iostream>
#include <string>
#include "account.h"
#include <vector>

using namespace std;

Account::Account()
{
    this->id = "unknown";
    this->name = "unknown";
    this->balance = 0;
}
Account::Account(string id, string name, double balance)
{
    this->id = id;
    this->name = name;
    this->balance = balance;
}
void Account::printAcct()
{
    cout << "{" << id << "," << name << "," << balance << "}" << endl;
}

void savemoney(Account &acct, double amount)
{
    if (amount <= 0)
    {
        cout << "必須存入正數!!" << endl;
        return;
    }
    acct.balance += amount;
}
void takemoney(Account &acct, double amount)
{
    if (amount > acct.balance)
    {
        cout << "存款不夠!!" << endl;
        return;
    }
    acct.balance -= amount;
}

void listallAcct(vector<Account> &customer)
{
    if (customer.size() == 0)
    {
        cout << "No Acct!" << endl;
        return;
    }
    for (int k = 0; k < customer.size(); k++)
    {
        customer[k].printAcct();
    }
}
void createAcct(vector<Account> &customer)
{
    string new_id;
    string new_name;
    double new_balance = 0;

    cout << "-----    add new account    ------" << endl;
    cout << "Please input account id:";
    cin >> new_id;
    cout << "Please input account name:";
    cin >> new_name;
    cout << endl;
    Account newcustomer(new_id, new_name, new_balance);
    customer.push_back(newcustomer);
    cout << "-----    add complete!      ------" << endl;
}

void deposit(vector<Account> &customer)
{
    string id;
    double amount = 0;
    cout << "-----    Deposit!           ------" << endl;
    cout << "Please input account id:";
    cin >> id;
    cout << "Please input deposit amount:";
    cin >> amount;
    for (auto &cus : customer)
    {
        if (id == cus.id)
        {
            savemoney(cus, amount);
            cout << "-----    Deposit Complete!  ------" << endl;
            return;
        }
    }
    cout << "-----    Deposit Failed!    ------" << endl;
}
void withdraw(vector<Account> &customer)
{
    string id;
    double amount = 0;
    cout << "-----    Withdraw!          ------" << endl;
    cout << "Please input account id:";
    cin >> id;
    cout << "Please input withdraw amount:";
    cin >> amount;
    for (auto &cus : customer)
    {
        if (id == cus.id)
        {
            takemoney(cus, amount);
            cout << "-----    Withdraw Complete! ------" << endl;
            return;
        }
    }
    cout << "-----    Withdraw Failed!   ------" << endl;
}
int menu(vector<Account> &acct_vect)
{
    cout << endl;
    cout << "-----  Welcome Bank system   -----" << endl;
    cout << "-----1.List all customer info-----" << endl;
    cout << "-----2.Add new customer      -----" << endl;
    cout << "-----3.Deposit money         -----" << endl;
    cout << "-----4.Withdraw money        -----" << endl;
    cout << "-----5.Exit                  -----" << endl;
    cout << endl;
    cout << "Enter your choice:";
    int choice = 0;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "-----1.List all customer info-----" << endl;
        listallAcct(acct_vect);
        cout << "-----1.List End!!!!!!!!!!!!!!-----" << endl;

        break;
    case 2:
        cout << "-----2.Add new customer      -----" << endl;
        createAcct(acct_vect);
        cout << "-----2.Add End!!!!!!         -----" << endl;
        break;
    case 3:
        cout << "-----3.Deposit               -----" << endl;
        deposit(acct_vect);
        cout << "-----3.Deposit End!!!!!      -----" << endl;
        break;
    case 4:
        cout << "-----4.Withdraw              -----" << endl;
        withdraw(acct_vect);
        cout << "-----4.Withdraw End!!!!!     -----" << endl;
        break;
    case 5:
        cout << "-----Exit System!!!!!        -----" << endl;
        break;
    default:
        cout << "-----         Exit           -----" << endl;
        break;
    }
    return choice;
}
