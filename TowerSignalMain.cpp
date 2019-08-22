#include <iostream>
#include "TowerSignal.h"
#include <string>
#include <fstream>

using namespace std;


int main()
{

	ifstream infile;//ifstream to readin the file
	string filename;//the following is a string for the file name
	int numbers;//integers that holds the value of the numbers read in from the file
	int x;//integer value for top tower
	myStack Tower;//Tower object that store all the number read in from the file
	myStack PlaceHolder;// Placeholder object holds the value of numbers that haven't been compared
	myStack Range;// Range object holds the value of each tower's range

	do
	{

		cout<< "Enter a filename: ";
		cin>> filename;

 		//filename.c_str() returns a C style string version
		infile.open(filename.c_str());

	}
	while(!infile.is_open());

	//the following while loop read in from the file and pushes it to myStack Tower
	while(!infile.eof())
	{

		infile>> numbers;
		Tower.push(numbers);
	
	}

	/*The following loop checks if the last number pushed in is larger than the number pushed before it.*/
	while(Tower.isEmpty()!= true)
	{
		int RangeCounter=1;	
		x= Tower.top();
		Tower.pop();

		//The following if statment checks if Tower is empty and if its it pushes rangecounter to Range
		if(Tower.isEmpty()==true)
		{
			Range.push(RangeCounter);
			break;
		}

		/*The following while loop checks x, which the last Tower.top() was pushed in, if the current Tower.
		top is less than x it push it to PlaceHolder and increments rangecounter by 1. */ 
		while(x > Tower.top())
		{
			PlaceHolder.push(Tower.top());
			Tower.pop();
			RangeCounter++;
		}

		Range.push(RangeCounter);

		//The following while loop pushes back the stored numbers in placeholder to Tower
		while(PlaceHolder.isEmpty() != true)
		{
			Tower.push(PlaceHolder.top());
			PlaceHolder.pop();
		}

	}

	cout<< "Here are the ranges for each tower"<< endl;

	//the following while loop keeps outputting the numbers pushed in reverse 
	while(Range.isEmpty()!= true)
	{
		cout<<Range.top()<<" ";
		Range.pop();
	}



	return 0;
}