#include <iostream>
#include <cmath>
#include "PondSimulation.h"

using namespace std;


int main()
{
	//the following are object's of herbivore and plant
	herbivore fish[200];
	plant plants[2000];
	int weeksinput;
	double psizeinput, prateinput, fsizeinput, frateinput;

	//prompt the user for weeks input
	cout<<" How many weeks would you like to simulate? ";
	cin>>weeksinput;

	//prompt the user of plant's size and rate input
	cout<<" Enter initial plant size and rate: ";
	cin>> psizeinput>> prateinput;

	//prompt the user for fish's size and rate input
	cout<<" Enter initial fish size and rate: ";
	cin>> fsizeinput>> frateinput;

	//temp objects that calls its counstrutor, passing the user input
	herbivore tempfish(fsizeinput, frateinput, fsizeinput* 0.1);
	plant tempplants(psizeinput, prateinput);


	//the following loop will traverse each element of plant and assign the temp plant object
	for(int i=0; i< 200; i++)
	{
		fish[i]= tempfish;
	}

	//the following will traverse each element of fish and assign the temp fish object 
	for(int i=0; i< 2000; i++)
	{
		plants[i]= tempplants;

	}

	int n=0;
	int randomfish;
	int randomplant;
	double PlantMass[weeksinput];

	//the following loop will set each element to zero
	for(int i=0; i< weeksinput; i++)
	{
		PlantMass[i]=0;
	}

	int FishAlive[weeksinput];

	// the followin loop will set each elemtn to zero
	for (int i = 0; i < weeksinput; ++i)
	{
		FishAlive[i]=0;
	}

	//the follwoing loop will run number of weeks input amount of times that will  contain other inner loops
	while(n< weeksinput)
	{
		int a=0;
		//The following loop will run amount of plants number of times and will randomly pick a fish and a plant adn this fish will cal its nibble function and pass in the plant chosen
		while( a< 2000)
		{
			randomplant= rand() % 2000;
			randomfish= rand() % 200;

			fish[randomfish].nibble(plants[randomplant]);
			a++;

		}

		//the follwoing loop will cal each plant's simulateWeek() function
		for(int i=0; i < 2000; i++)
		{
			plants[i].simulateWeek();
		}

		// the following loop will call each fish's simulateWeek() funciton
		for(int i=0; i< 200; i++)
		{
			fish[i].simulateWeek();
		}

		//the following loop will add up all the masses of all the plants
		for(int i=0; i< 2000; i++)
		{

				PlantMass[n]+= plants[i].getSize();

		}

		//the follwoing loop will add up all the living fish
		for(int i=0; i< 200; i++)
		{
			if(fish[i].isAlive()== true)
			{
				FishAlive[n]++;
			}
			
		}


		n++;
	}

	int f=1;
	// The following outputs all the living fish and total mass of the plants
	for( int i=0; i< weeksinput; i++)
	{
		cout<< "Week "<< f << " Amount of fish.........."<<FishAlive[i]<< "      ";
		cout<< " Mass of Plants.........."<<PlantMass[i]<< endl;
		f++;
	}





	return 0;
}