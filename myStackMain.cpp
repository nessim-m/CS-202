#include <iostream>
#include <string>
#include "myStack.h"

using namespace std;



int main()
{
	string str;// string variable to cin user input

	cout<< "Enter the arithmetic expression: ";

	getline(cin, str);

	int leftside=0;
	int rightside=0;// int counter variable
	int k=0;// int counter variable

	//the following while loop counts how many of the following specified characters below was read in
	while(str[k] != '\0')
	{
		//if it read a the following characters it incremnet rightside by 1
		if(str[k] == '[' or str[k] == '(' or str[k] == '{')
		{
			rightside++;
		}
		//if it read a the following characters it incremnet leftside by 1
		if(str[k] == ']' or str[k] == ')' or str[k] == '}')
		{
			leftside++;
		}

		k++;
	}

	//if the leftside does not equal to the right side then it output the following and terminate the program
	if(leftside!= rightside)
	{
		cout<< "Oops, looks like something went wrong" << endl;
		return 0;

	}

	myStack list(rightside);// mystack object with a size of the user's input

	int i=0;

	/*The following while loop runs through the end of the line read in.*/
	while(str[i]!= '\0')
	{	
		//if the following characters are read, it pushes it to the list object
		if(str[i] == '[' or str[i] == '(' or str[i] == '{')
		{
			list.push(str[i]);
		}

		//if the following character read in from string matches with the last character pushed to list's object, it pops it
		if(list.top() == '[' and str[i] == ']')
		{
			list.pop();
		}

		//if the following character read in from string matches with the last character pushed to list's object, it pops it
		if(list.top() == '{' and str[i] == '}')
		{
			list.pop();
		}

		///if the following character read in from string matches with the last character pushed to list's object, it pops it
		if(list.top() == '(' and str[i] == ')')
		{
			list.pop();
		}

		i++;
	}

	//The following calls the empty funciton, if returns true it outputs the following
	if(list.isEmpty() == true)
	{
		cout<< "All brackets/parenthesis are matched correctly" << endl;
	}
	//If the function called returns false it output the following
	else
	{
		cout<< "Oops, looks like something went wrong" << endl;
	}


	return 0;
}