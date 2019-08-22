#include <iostream>
#include <fstream>
#include <string>
#include "bankBranch.h"

using namespace std;


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