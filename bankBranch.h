#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>
//#include "bankBranch.h"


using namespace std;

class bankBranch//banBranch of class type
{
public:
	bankBranch();//constructor that initialize variables to zero
	void addAccount(string, string, long, short, double);//function that assigns the account's info to the private variables
	int searchAccounts(long) const;//function that search for the account number stored
	bool verifyAccount(int, short);//function that verify the accounts pin
	bool updateAccount(int, double);//function that updates the account's balance
	void outputUserInfo(int) const;// function the outputs account's info

private:
	int amountOfAccounts;// represents the number of bank accounts
	string first[20];//contains all the first names for the bank accounts
	string last[20];//contains all the last names for the bank accounts
	double amount[20];// contains the balance for each account
	long acctNo[20];//contains the account number for each account
	short pin[20];//contains the pin for each account
	short attempts[20];// represents the number of failed attempts to enter the pin for each account
};

const int zero=0;// a constant value that hold a vlue of zero thorugh out the code.
