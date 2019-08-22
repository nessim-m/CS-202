#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>
#include "bankBranch.h"

using namespace std;



//the following constructor just initialize the private varibales to zero 
bankBranch::bankBranch()
{
	amountOfAccounts=zero;

	for(int i=0; i< 20; i++)
	{
		attempts[i]=zero;
	}

}


//the following function assigns value to the account's info arrays
void bankBranch::addAccount(string f, string l, long acct, short p, double amt )
{

	first[amountOfAccounts]=f;
	last[amountOfAccounts]=l;
	acctNo[amountOfAccounts]=acct;
	pin[amountOfAccounts]=p;
	amount[amountOfAccounts]=amt;

	amountOfAccounts++;



}

/*the following function just searches through the list of accounts' numbers and checks if they match.
If they dont match it returns -1.*/
int bankBranch::searchAccounts(long acct) const
{

	for( int i=0; i< amountOfAccounts; i++)
	{
		if(acct==acctNo[i])
		{
			return i;
		}
	}

	return -1;



}

/* the following function checks if the input account pin matches with the listed accounts' pins in the file
 and increment attempts by 1 if the enter pin for the selected account was incorrect.*/
bool bankBranch::verifyAccount(int index, short p)
{

	int failedattempts=1;

	if( pin[index]==p and attempts[index]< 3)
	{

		return true;
	}


	else if( pin[index]!=p or  attempts[index] >= 3)
	{
		attempts[index]+=failedattempts;

		return false;		
	}

}

// the following function updates the selected account's amount
bool bankBranch::updateAccount(int index, double amt)
{


	if ( amount[index] > zero or amt> zero)
	{
		amount[index]+= amt;

		return true;		
	}

	else if( amount[index]<= zero)
	{
		return false;
	}

}

// the following function outputs the account's info
void bankBranch::outputUserInfo(int index) const
{
	cout<< fixed;
	cout << "Name:"<<setw(11)<<last[index]<< ", " << first[index]<< endl;
	cout << "AcctNo:"<<setw(14)<< acctNo[index]<< endl;
	cout << "Balance...$"<<setprecision(2)<<setw(10)<< amount[index]<< endl;
	cout << endl;

}