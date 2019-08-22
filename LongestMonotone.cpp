#include <iostream>
#include <fstream>


using namespace std;



int main()
{
	ifstream infile;
	string filename;
	int *listOfItems;//the following is single pointer that hold  value read in from the file
	int capacity=5;// this is decleared variable that holds the capacity of the array
	int *MonotoneLength;//the following is a single pointer 

	listOfItems= new int[capacity];//array of pointer, this will represents the number of rows

	//the following reprompts the user for a valid file name
	do
	{
		cout<<" Enter input file: ";
		cin>> filename;

		infile.open(filename.c_str());
	}
	while(!infile.is_open());

	int index = 0;

	//The following is loop that reads in from the file
	while(infile >> listOfItems[index])
	{
		index++;

		/*the following if the capacity is full and creates a temprory array of pointer
		and resize the orginal array of pointer by 5 and preforms a deep copy, then deallocates the previous
		array of pointer*/
		if(index == capacity)
		{
			capacity+= 5;

			int *tmp= new int[capacity];

			for(int i=0; i< capacity; i++)
			{
				tmp[i]= listOfItems[i];
			}

			delete [] listOfItems;

			listOfItems = tmp;
		}
	}

	MonotoneLength= new int[index];//array of pointer, this will represents the number of rows

	// assigns a value of 1 to the whole array
	for( int i=0 ; i< index; i++)
	{
		MonotoneLength[i]= 1;
	}

	int position=0;



		/*The following are loops checks for montone subsequence and increments the position
	 by 1*/
	for(int i=1; i< index; i++)
	{
		for(int j=0; j< i; j++)
		{	
			//This checks if the positon before the current, starting from 0 are smaller than the current and the opposite for Monotone Length array
			if(listOfItems[i] > listOfItems[j] and  MonotoneLength[j] >= MonotoneLength[i])
			{	
				//The following does the same thing as the previous if statment but for the monotonelength array of pointer
				
					MonotoneLength[i]= MonotoneLength[j] + 1;

			}
		}
	}



	int MaxNum;

	/*The following loop checks  for largest number in the array of pointers MonotoneLength*/
	for(int i=1; i<index ; i++)
	{
		int n=1;
		while(n <= i)
		{

		if(MonotoneLength[i] > MonotoneLength[i-n])
		{
			MaxNum= i;
		}

		n++;

		}
	}

	cout<<" The length of the longest montone subsequence is "<< MonotoneLength[MaxNum]<< endl;// This output the longest montone subsequence

	return 0;
}