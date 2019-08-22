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

int main()
{

	bankBranch Accounts;//onject of type bankBranch

	//necessary variables that contains value for the bank account's info
	string f,l;
	double amt;
	short p;
	long acct;
	string filename;
	ifstream infile;
	int TotalAccounts;
	long accountnumberinput;
	short accountpin;
	char usercontinue;
	double amountinput;
	char WD;

	cout << "Enter file name to begin this program...again: ";
	cin>> filename;
	infile.open(filename.c_str());

	while(cin.fail() or !infile.is_open())
	{
		cout<< "Ahem...let's try this again: ";
		cin>> filename;

		infile.open(filename.c_str());
	}

	infile>> f;

	while(!infile.eof())
	{
		infile>> l>> acct>> p>> amt;

		Accounts.addAccount(f,l,acct,p,amt);

		infile>> f;

		//cout<< f<<" "<<l<< " "<<acct<<" "<<p<<" "<<amt<< endl;
	}

	infile.close();


	//The following outputs and prompt user to enter a valid account number.
	cout <<  "Enter account number: ";
	cin >> accountnumberinput;

	//reprompt the user to enter a valid account number.
	while(cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');

		cout <<  "Enter account number: ";
		cin >> accountnumberinput;

	}

		/*the following preform a search for the account number entered by user if it exist inside the file sorted.
	As well as, it calls the output function to output the information if the account exist or output not found if not and ask
	 if the user want to continue or not.*/
	while(!cin.fail())
	{
		int index;

		index= Accounts.searchAccounts(accountnumberinput);


		if(index==-1)
		{
			cout<<"Account not found! :("<<endl;

		}

		else
		{
			int pincheck;
			cout<< "Enter pin: ";
			cin>> accountpin;

			pincheck= Accounts.verifyAccount(index, accountpin);

			if(pincheck== false)
			{
				cout<< endl;

				cout<<"Account frozen or incorrect pin entered, exiting account"<< endl;

			}

			else if (pincheck== true)
			{
				Accounts.outputUserInfo(index);

				cout << "Would you like to make a withdrawl or deposit? (W/D): ";
				cin >> WD;

				while ( WD!='W' or WD!='w' or WD!='D' or WD!='d')
				{

					if(WD== 'W' or WD== 'w' or WD== 'D' or WD== 'd')
					{
						break;
					}

					cout << "Invalid option!" << endl;

					cin.clear();
					cin.ignore(100,'\n');

					cout << "Would you like to make a withdrawl or deposit? (W/D): ";
					cin >> WD;


				}

				if( WD== 'W' or WD== 'w')
				{
					int check;

					cout<< "Enter an amount you would like to withdrawl: ";
					cin >> amountinput;

					while(cin.fail() or amountinput <= zero)
					{
						cin.clear();
						cin.ignore(100,'\n');

						cout<< "Invalid amount entered! >:("<< endl;
						cout<< "Enter an amount you would like to withdrawl: ";
						cin >> amountinput;
					}

					check= Accounts.updateAccount(index, -amountinput);

					if( check== false)
					{
						cout << "Cannot proccess transaction...O.o"<< endl;
					}
				}

				else if ( WD== 'D' or WD== 'd')
				{
					cout << "Enter an amount you would like to deposit: ";
					cin>> amountinput;

					while(cin.fail() or amountinput <= zero )
					{
						cin.clear();
						cin.ignore(100,'\n');

						cout<< "Invalid amount entered! >:("<< endl;
						cout<< "Enter an amount you would like to deposit: ";
						cin >> amountinput;
					}

					Accounts.updateAccount(index, amountinput);

				}



			}

		}



		cout<<endl<< "Do you wish to continue? (Y/N): ";
		cin>> usercontinue;
		cout<<endl;

		while(!cin.fail())
		{
			if(usercontinue=='Y' or usercontinue=='y')
			{
				break;
			}

			else if(usercontinue=='N' or usercontinue=='n')
			{
				cout<< "Have a great day! :)"<< endl;

				return 0;

			}


			cout<<endl<< "Do you wish to continue? (Y/N): ";
			cin>> usercontinue;
			cout<<endl;
		}

		cout <<  "Enter account number: ";
		cin >> accountnumberinput;

		while(cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');

			cout <<  "Enter account number: ";
			cin >> accountnumberinput;

		}
	}


	return 0;
}

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