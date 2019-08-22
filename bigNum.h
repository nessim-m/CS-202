#include <iostream>
#include <cmath>


using namespace std;


class bigNum
{
	public :
	static const int MAX_DIGITS = 50;// a constant value that represents maximum number of posisitons in the array  
	bigNum ();// its a default constructor that initilize the private variables
	bigNum ( const char []);// it a constructor that takes in a char type and assign the private variables
	bigNum ( int );// its a constructor that takes in an int type and convert it to char type and assign it  to the private variables
	bigNum operator +( const bigNum &) const ;//its an operator that takes in two char type and preform addition and return the sum
	bigNum operator +( int ) const ;// its an operator that takes in an integer and preform an addition and return the sum
	bigNum operator -(const bigNum&) const;
	bigNum operator -(int) const;
	bool operator <( const bigNum &) const ;// its an operator that takes in a char type and preform comparsion of less than between two big numbers and return true or false
	bool operator <( int ) const ;// its an operator that takes in an int type and  preform a comparsion of less than between two big numbers and return true or false
	bool operator ==( const bigNum &) const ;// its an operator that takes in a char type and preform a comparsion of equality between two big numbers and return true or false
	bool operator ==( int ) const ;// its an operator that takes in an int type and preform a comparsion of equality between two big numbers and return true or false
	friend bigNum operator +( int , const bigNum &);// its an operator that takes in an int and char type and preform an addition and returns the sum
	friend bigNum operator -(int, const bigNum&);
	friend bool operator <( int , const bigNum &);// its an operator that takes in an int and char type and preform a comparsion of less than between two big number and return true or false
	friend bool operator ==( int , const bigNum &);// its an operator that takes in an int and char type and preform a comparsion of equality between two big number and return true or false
	friend ostream & operator <<( ostream & , const bigNum &);// its an operator that preform outputs
	friend istream & operator >>( istream & , bigNum &);// its an operator that preform inputs and assign the userinput
	private :
	int amtDigits ;// its a private variable that represents the amount of digits the object contains
	char number[MAX_DIGITS];// its a private variable that stores a char array of numbers
};