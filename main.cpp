#include <iostream>
#include <vector>
#include <string>
#include "account.cpp"

#define EXIT_FLAG 5;

using namespace std;
int main()
{

    vector<Account> acct_vect;

    int flag = 0;
    int E_FLAG = EXIT_FLAG;
    while (flag != E_FLAG)
    {
        /* code */
        flag = menu(acct_vect);
    }
    return 0;
}