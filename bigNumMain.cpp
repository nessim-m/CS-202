#include <iostream>
#include <cmath>
#include "bigNum.h"

using namespace std;




int main()
{

	bigNum n1 ( "000009999999999999999999999999" );//its bigNum object that passes char type
	bigNum n2 (116986);// its a bigNum object that passes an int type
	bigNum n3 ;//its a bigNum object that passes the userinput
	bigNum n4 ;//its a bigNum object that passes the userinput
	bigNum onlyUsedInAssign ; // its a bigNum that contains a value of a sum that the addition operator returned

	/*the following preforms addititon, subtraction checking all the operator that adds
	or subtract two objects regardles of the type that is been passed to this operators, it calls the right operator according
	to its paramter,and assign the result to the object onlyUsedInAssign.
	Also, outputs the object everytime it preform some addition or subtraction.*/
	cout << endl ;
	cout << " Enter two big numbers : " ;//it output text on the screen
	cin >> n3 >> n4 ;// it calls the istream operator
	cout << endl << " Contents of variables " << endl ;//
	cout << " n1 = " << n1 << endl ;
	cout << " n2 = " << n2 << endl ;
	cout << " n3 = " << n3 << endl ;
	cout << " n4 = " << n4 << endl << endl ;
	cout << " Testing out operators " << endl ;
	onlyUsedInAssign = n1 + 1;
	cout << " n1 + 1 = " << onlyUsedInAssign << endl ;
	onlyUsedInAssign = n2 + 189765;
	cout << " n2 + 189765 = " << onlyUsedInAssign << endl ;
	onlyUsedInAssign = n2 + n3 ;
	cout << " n2 + n3 = " << onlyUsedInAssign << endl ;
	onlyUsedInAssign = 8765309 + n4 ;
	cout << " 8765309 + n4 = " << onlyUsedInAssign << endl ;
	onlyUsedInAssign = n1 - 1;
	cout<< " n1 - 1 = " << onlyUsedInAssign<< endl;
	onlyUsedInAssign = n2 - 189765;
	cout<< " n2 - 189765 = " << onlyUsedInAssign << endl;
	onlyUsedInAssign = n2 - n3;
	cout<< " n2 - n3 = " << onlyUsedInAssign<< endl;
	onlyUsedInAssign = 8765309 - n4;
	cout<< " 8765309 - n4 = " << onlyUsedInAssign << endl;

	/*The following preforms comparsion between objects. As well as, numbers with objects by calling the right operator
	according to its paramter, and then outputs the comparsion on the screen.*/
	if ( n3 == n4 )
		cout << " n3 equals n4 " << endl ;
	else
		cout << " n3 does NOT equal n4 " << endl ;
	if ( n3 == 32536)
		cout << " n3 eqauls 32536 " << endl ;
	else
		cout << " n3 does NOT equal 32536 " << endl ;
	if ( n3 < n4 )
		cout << " n3 is less than n4 " << endl ;
	else
		cout << " n3 is NOT less than n4 " << endl ;
	if ( n4 < 8976534)
		cout << " n4 is less than 8976534 " << endl ;
	else
		cout << " n4 is NOT less than 8976534 " << endl ;
	if (8976534 < n3 )
		cout << " 8976534 is less than n3 " << endl ;
	else
		cout << " 8976534 is NOT less than n3 " << endl ;
	if (32536 == n2 )
		cout << " 32536 is equal to n2 " << endl ;
	else
		cout << " 32536 is NOT equal to n2 " << endl ;
	return 0;
}