#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>


using namespace std;

/* a struct type that holds members of bank account information.
Such as: first and last name of the account holder. As well as, the balance in the account,
the account number, and four digit pin number of the account.*/
struct bankAcct
{
	string first, last;
	double amount;
	long acctNo;
	short pin;
	
};

int storeInfo(bankAcct[], ifstream&);// A function that stores the file of bank accounts into an array.
int sort(bankAcct[], int);// A function that sorts the bank account numbers from least to greatest in order.
int search(bankAcct[], int, long);// A function that searches through the sorted arry of bank account numbers.
void outputAndHandleRequest(bankAcct&);//A function that output bank account information and modify account balance upon request.

const int twenty= 20;// A constant value that holds a value of twenty throughout the code.
const double zero= 0.0;// A constant value that holds a value of zero throughout the code.

int main()
{
	// declared variable to hold values after the input from user. 
	bankAcct account[twenty];// declared struct of array with maximum of twenty. 
	ifstream infile;
	string filename;
	int TotalAccounts;
	long accountnumber;
	int searchh;
	int accountpin;
	char usercontinue;

	//prompt user to enter a valid file name.
	do
	{

		cout<< "Enter a filename: ";
		cin>> filename;

 		//filename.c_str() returns a C style string version
		infile.open(filename.c_str());

	}
	while(!infile.is_open());

	//The following passes the total number of accounts read from the file.
	TotalAccounts= storeInfo(account, infile);

	//The following sorts the file read in order, from least to greatest.
	sort(account, TotalAccounts);


	//The following outputs and prompt user to enter a valid account number.
	cout <<  "Enter account number: ";
	cin >> accountnumber;

	//reprompt the user to enter a valid account number.
	while(cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');

		cout <<  "Enter account number: ";
		cin >> accountnumber;

	}

	/*the following preform a search for the account number entered by user if it exist inside the file sorted.
	As well as, it outputs the information if the account exist or output not found if not and ask
	 if the user want to continue or not.*/
	while(!cin.fail())
	{

		searchh= search(account, TotalAccounts, accountnumber);

		if(searchh==-1)
		{
			cout<<"Account not found! :("<<endl;

		}

		else
		{
			cout<< "Enter pin: ";
			cin>> accountpin;

			if(accountpin==account[searchh].pin)
			{
				cout<< endl;

				outputAndHandleRequest(account[searchh]);

			}

			else
			{
				cout<<"Incorrect pin, exiting out of account"<< endl;
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
		cin >> accountnumber;

		while(cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');

			cout <<  "Enter account number: ";
			cin >> accountnumber;

		}
	}



	return 0;
}


// A function that stores the file of bank accounts into an array
int storeInfo(bankAcct account[], ifstream& infile)
{
	int counter =0;



	infile>> account[counter].first;

	while(!infile.eof())
	{

		infile>> account[counter].last>> account[counter].acctNo>> account[counter].pin>> account[counter].amount;

		counter++;

		infile>> account[counter].first;

	}

	return counter;



}

// A function that sorts the bank account numbers from least to greatest in order.
int sort(bankAcct account[], int TotalAccounts)
{
	int i,j;
	bankAcct temporary;

	for (i=0; i< TotalAccounts; i++)
	{
		for (j=i+1; j<TotalAccounts; j++)
		{
			if(account[i].acctNo > account[j].acctNo)
			{
				temporary= account[i];
				account[i]= account[j];
				account[j]= temporary;
			}
		}
	}

}

// A function that searches through the sorted arry of bank account numbers.
int search(bankAcct account[], int TotalAccounts, long accountnumber)
{
	int l,m,r;

	l=0;
	r=TotalAccounts-1;

	while(l<=r)
	{
		m= (l+r)/2;

		if (account[m].acctNo== accountnumber)
		{
			return m;
		}

		if (account[m].acctNo < accountnumber)
		{
			l=m+1;
		}

		else if(account[m].acctNo > accountnumber)
		{
			r=m-1;
		}

		
	}

	return -1;


}


//A function that output bank account information and modify account balance upon request.
void outputAndHandleRequest(bankAcct& account)
{
	char WD;
	double amount;

	cout<< fixed;
	cout << "Name:"<<setw(11)<<account.last<< ", " << account.first<< endl;
	cout << "AcctNo:"<<setw(14)<< account.acctNo<< endl;
	cout << "Balance...$"<<setprecision(2)<<setw(10)<< account.amount<< endl;
	cout << endl;

	cout << "Would you like to make a withdrawl or deposit? (W/D): ";
	cin >> WD;


	while (WD!='W' or WD!='w' or WD!='D' or WD!='d')
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
		cout<< "Enter an amount you would like to withdrawl: ";
		cin >> amount;

		while(cin.fail() or amount <= zero)
		{
			cin.clear();
			cin.ignore(100,'\n');

			cout<< "Invalid amount entered! >:("<< endl;
			cout<< "Enter an amount you would like to withdrawl: ";
			cin >> amount;
		}

		if ( account.amount > zero)
		{
			account.amount= account.amount - amount;
		}

		else
		{
			cout << "Cannot proccess transaction...O.o"<< endl;
		}
	}

	else if ( WD== 'D' or WD== 'd')
	{
		cout << "Enter an amount you would like to deposit: ";
		cin>> amount;

		while(cin.fail() or amount <= zero )
		{
			cin.clear();
			cin.ignore(100,'\n');

			cout<< "Invalid amount entered! >:("<< endl;
			cout<< "Enter an amount you would like to deposit: ";
			cin >> amount;
		}

		if (amount > zero)
		{

			account.amount= account.amount + amount;

		}

		

	}





}
