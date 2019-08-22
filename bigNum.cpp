#include <iostream>
#include <cmath>
#include "bigNum.h"


using namespace std;



/* the following is a constructor that initialize the private variables to zero for the int type amount of digits
	and a character '0' to the char type that stores big numbers in an array.*/
bigNum::bigNum ()
{
	amtDigits=0;// it sets the integer amount of digits to zero.

	// the following is a for loop that stores a character 0 to the objects number, starting from 0 to 49.
	for( int i=0; i< MAX_DIGITS; i++)
		number[i]='0';

}
/*The following is another constructor that does the samething as the previous constructor. However,
this constructor takes in characters only.*/
bigNum::bigNum ( const char strNum[])
{
	int pos = 0;
	amtDigits = 0;

	for( int i=0; i< MAX_DIGITS; i++)
		number[i]='0';

	// the following filter out leading zeros
	while (strNum[pos] == '0')
		pos++;

	int start = pos;//the starting positon of the whole number

	/*the following counts all the digits in the number after the leading zeros.
	*/
	while (strNum[pos] != '\0')
	{
		pos++;
		amtDigits++;
	}

	/* the following is a loop that starts from zero to the amount of digits that was generated
	 from the last loop and copies each character from strNum into the object's number*/
	for(int i=0; i< amtDigits; i++)
		number[MAX_DIGITS - amtDigits + i]= strNum[start +i];

}

/*The following is another constructor that does the exact same thing as the first constructor
but the only differenece is it takes in an integer type only*/
bigNum::bigNum ( int n)
{
	int extracted;
	amtDigits=0;

	for( int i=0; i< MAX_DIGITS; i++)
		number[i]='0';

	/* the following is while loop that converts the integer n to a character and store each digit at a time into
	 the object's number and increment the objects amount of digits by 1 everytime it stores a digit.*/
	while(n!=0)
	{
		amtDigits++;
		extracted= n % 10;
		extracted+= '0';
		number[MAX_DIGITS- amtDigits]= extracted;
		n/= 10;
	}

}
/*The following is a bigNum operator that preforms additon when its called and returns the sum.
This operator only takes character type.*/
bigNum bigNum::operator +( const bigNum & rhs) const 
{
	bigNum temporary;
	int n=1;

	/*The follwoing is a while loop that starts from the number's array position 49
	untill the last digit before the leading character 0. It extract each digit at a time from
	both object's number and preform addition, and store the sum into a temporary's number and return it.*/
	while(n<= amtDigits || n<= rhs.amtDigits)
	{
		int extracted1= number[MAX_DIGITS - n] - '0';
		int extracted2= rhs.number[MAX_DIGITS - n] - '0';
		int value= extracted1 + extracted2;

		while( value >= 10)
		{
			int mod= value % 10;
			temporary.number[MAX_DIGITS -n]= mod + '0';
			mod= value / 10;
			n++;
			extracted1= number[MAX_DIGITS - n] - '0';
			extracted2= rhs.number[MAX_DIGITS - n] - '0';
			value= extracted1 + extracted2 + mod;
		}

		temporary.number[MAX_DIGITS -n]= value + '0';
		n++;
	}


	return temporary.number;

}

/*The following is a bigNum operator that preforms subtraction when its called and returns the subtracted number.
This operator only takes character type.*/
bigNum bigNum::operator -(const bigNum& rhs) const
{
	// the following are decleared variables and objects.
	int extracted1;
	int extracted2;
	int value;
	int n=1;
	int a=0;
	int borrowed=1;
	int peek;
	bigNum temporary;
	bigNum n1(number);
	bigNum n2(rhs.number);
	bigNum largnum;
	bigNum smallnum;

	//the following if statment checks if n1's number is less than n2's number
	if(n1<n2)
	{
		largnum= n2;
		smallnum= n1;
	}

	// the following else statment is if n1's is greater than or equal to n2's number
	else
	{
		largnum=n1;
		smallnum=n2;
	}

	/*The following while loop preforms a subtraction, the smallnum's number from largnum's number*/
	while(n<= largnum.amtDigits)
	{
		extracted1= largnum.number[MAX_DIGITS-n] - '0';
		if(n==a)
		{
			extracted1= extracted1 - 1;
		}
		extracted2= smallnum.number[MAX_DIGITS-n] - '0';

		// the following loop is if the extracted1 was less than extracted2
		while(extracted1 < extracted2)
		{
			// this if statment works only if the current positon of largnum's number is greater than 0 or its 0 but the previous position was greater than 0. 
			if(largnum.number[MAX_DIGITS-n+1]-'0'!= 0 and largnum.number[MAX_DIGITS-n]-'0'==0 or largnum.number[MAX_DIGITS-n]-'0' > 0)
			extracted1= extracted1 + 10;

			//if previous statment is false then store 9 to to it
			else
			{
				extracted1=9;
			}
			value= extracted1 - extracted2;

			temporary.number[MAX_DIGITS-n]= value + '0';
			n++;

			peek= largnum.number[MAX_DIGITS-n] - '0';

			// this if statment set a=n if peek is 0
			if (peek==0)
			{
				a=n;
			}

			// this while loop check if there is more than one zero and stores the next postion that is greater than 0
			while(peek==0)
			{
				a++;
				peek= largnum.number[MAX_DIGITS-a] -'0';
				
			} 

			extracted1= largnum.number[MAX_DIGITS-n]-'0';

			// this if statement stores 9 if extracted1 = 0
			if( extracted1==0)
			{
				extracted1 = 9;
			}
			//if the previous statment was false and n equals a then it subtract extracted1 by 1
			else if(n==a)
			{
				extracted1= extracted1 - 1;
			}

			// else if both previous statments were false than it subtract extracted1 by borrowed which is by 1
			else
			{
				extracted1= extracted1 - borrowed;
			}

			extracted2= smallnum.number[MAX_DIGITS-n] - '0';
		}

		//the following just preform subtraction and store it to value and store value to the temporary's number.
		value= extracted1 - extracted2;
		temporary.number[MAX_DIGITS-n]= value + '0';
		n++;
	}

	return temporary.number;


}
/*The following operator gets called when a subtracting an integer type from char type*/
bigNum bigNum::operator -(int rhs) const
{
	// the following stores the integer into a new object and calls the integer constructor.
	// it also store the object's number that called this operator int a temporary object.
	// then it calls the previous subtraction operator char type and return the subtracted number.
	bigNum intnum(rhs);
	bigNum n(number);
	bigNum temporary;

	return temporary= n.operator -(intnum);
}
/*The following operator gets called when adding an integer type from char type*/
bigNum bigNum::operator +( int rhs) const 
{
	// the following stores the integer into a new object and calls the integer constructor.
	// it also store the object's number that called this operator int a temporary object.
	// then it calls the previous addition operator char type and return the subtracted number.
	bigNum intnum(rhs);
	bigNum n(number);
	bigNum temporary;

	return temporary= n.operator +(intnum);

}
/*The follwoing operator gets called when two objects are being compared to determine if the left hand side is less thant he right hand side
and then it returns true or false*/
bool bigNum::operator <( const bigNum & rhs) const 
{
	int check = false;

	//the following checks the objects amount of digts if the l.h.s. is less than the r.h.s. then it  sets check= to true.
	if( amtDigits < rhs.amtDigits)
	{
		check= true;
	}
	int n=0;
	// this while loop is if  it didnt enter the previous if statment. If check is still false then it checks every object's number at a time
	// by comparing them to each other and then returns true or false
	while( check== false || n<50)
	{
		int extracted1= number[MAX_DIGITS - amtDigits + n] - '0';
		int extracted2= rhs.number[MAX_DIGITS- amtDigits + n] - '0';
		n++;
		if( extracted1 < extracted2)
		{
			check= true;
		}
		else if( extracted1 > extracted2)
		{
			break;
		}
	}

	return check;


}

/*The follwoing operator gets called when two objects are being compared to determine if the left hand side is less thant he right hand side
and then it returns true or false, but in this case the r.h.s. is an integer not an object*/
bool bigNum::operator <( int rhs) const 
{
	//the follwoing stores the int r.h.s. to a new object and the l.h.s. object's number to a new object
	//then it calls the previous operator, since we are comparing two objects and it store it into a integer temporary and return it. 
	bigNum intnum(rhs);
	bigNum n(number);
	int temporary;

	return temporary= n.operator <(intnum);

}

/*The follwoing operator gets called when two objects are being compared to determine if the left hand side is equal to he right hand side
and then it returns true or false*/
bool bigNum::operator ==( const bigNum & rhs) const 
{
	int check= false;
	int n=0;


	// the following checks the objects' number each at a time and compare them if they are equal
	while( check== false or n<50)
	{
		// if the amount of digits are nnot equal then it breaks the loop and return false
		if( amtDigits != rhs.amtDigits)
		{
			break;
		}

		int extracted1= number[MAX_DIGITS - amtDigits + n]- '0';
		int extracted2= rhs.number[MAX_DIGITS - amtDigits + n] -'0';
		// if the extracted1 is not equal to extracted2 then it also breaks and return false
		if(extracted1 != extracted2)
		{
			break;
		}
		else
		{
			n++;
			if(n == amtDigits)
			{
				check= true;
				break;
			}
		}
	}

	return check;

}

/*The following operator gets called when two objects are being compared to determine if the left hand side is equal to he right hand side
and then it returns true or false, but in this case if the r.h.s. is an integer*/
bool bigNum::operator ==( int rhs) const 
{
	//the following stores the int rhs to a new object and the number of the object into another new object
	// then it calls the previous equalitiy check operator, since we comparing two objects and then it return true or false by storing it to the int type temporary
	bigNum intnum(rhs);
	bigNum n(number);
	int temporary;

	return temporary= n.operator ==(intnum); 

}
/*The following operator gets called when a subtracting an char type from int type*/
bigNum operator -(int lhs, const bigNum& rhs)
{
	// the following stores the integer lhs into a new object and calls the integer constructor.
	// it also store the object's number that called this operator int a temporary object.
	// then it calls the previous subtraction operator char type and return the subtracted number.
	bigNum intnum(lhs);
	bigNum n(rhs);
	bigNum temporary;

	return temporary= intnum.operator -(n);
}

/*The following operator gets called when adding an char type from int type*/
bigNum operator +( int lhs , const bigNum& rhs)
{
	// the following stores the integer into a new object and calls the integer constructor.
	// it also store the object's number that called this operator int a temporary object.
	// then it calls the previous addition operator char type and return the subtracted number.
	bigNum intnum(lhs);
	bigNum n(rhs);
	bigNum temporary;

	return temporary= intnum.operator +(n);

}
/*The follwoing operator gets called when two objects are being compared to determine if the left hand side is less thant he right hand side
and then it returns true or false, but in this case the l.h.s. is an integer not an object*/
bool operator <( int lhs, const bigNum & rhs)
{
	//the follwoing stores the int l.h.s. to a new object and the r.h.s. object's number to a new object
	//then it calls the previous operator, since we are comparing two objects and it store it into a integer temporary and return it.
	bigNum intnum(lhs);
	bigNum n(rhs);
	int temporary;

	return temporary= intnum.operator <(n);

}

/*The following operator gets called when two objects are being compared to determine if the left hand side is equal to he right hand side
and then it returns true or false, but in this case if the r.h.s. is an integer*/
bool operator ==( int lhs, const bigNum & rhs)
{
	//the following stores the int rhs to a new object and the number of the object into another new object
	// then it calls the previous equalitiy check operator, since we comparing two objects and then it return true or false by storing it to the int type temporary
	bigNum intnum(lhs);
	bigNum n(rhs);
	int temporary;

	return temporary= intnum.operator ==(n);

}
/*The following operator is ostream which it outputs bN's number*/
ostream& operator <<( ostream& out, const bigNum& bN)
{
	// the following is a for loop that outputs the bN's number with out the leading zeros
	for( int i=bN.MAX_DIGITS - bN.amtDigits; i< bN.MAX_DIGITS; i++)
		out<< bN.number[i];

	return out;
}
/*The following is istream, prompts the user to input a two big numbers and store this nummbers to objects*/
istream& operator >>( istream & in, bigNum & bN)
{
	//the following is char array and prompt the user to enter big numberss
	char userinput[bN.MAX_DIGITS];
	in>> userinput;

	// the following is an object that stores the big number  and call the right constructor according to the user's input
	bigNum temporary(userinput);

	// thiss sets the object temp into object bN
	bN= temporary;

	return in;

}