#include <iostream>
#include <cmath>
#include "PondSimulation.h"

using namespace std;

//*************************************************
//The members of organism class are described below
//*************************************************

//The following is a constructor that sets growthRate and size with the values passed in
organism::organism(double initSize, double initRate)
{
	growthRate= initRate;
	size= initSize;

}

//The following increments the size by growthRate
void organism::simulateWeek()
{
	size+= growthRate;

}

//The following assigns growthRate with the value passed in
void organism::assignRate(double newRate)
{
	growthRate= newRate;

}

//The following increments the size by the amount passed in
void organism::alterSize(double amount)
{

	size+= amount;
}

//The following sets growthRate and size to 0
void organism::death()
{
	growthRate=0;
	size=0;

}

//The following returns size
double organism::getSize() const
{
	return size;

}

//The following returns growthRate
double organism::getRate() const
{
	return growthRate;

}

//The following returns true if size is larger than 0, otherwise it returns false
bool organism::isAlive() const
{
	bool check;

	if(size > 0)
	{
		check= true;
	}
	else
	{
		check= false;
	}

	return check;

}

//*********************************************
//The members of plant class are described below
//*********************************************

//The following is a constructor that sets growthRate and size with the value passed in
plant::plant(double initSize, double initRate):organism(initSize, initRate)
{


}

//The following decreases the size by amount, if the amount is larger than the size, then it set the size to 0
void plant::nibbledOn(double amount)
{
	double tempsize;

	

	if( amount > getSize())
	{
		
		tempsize= getSize();
		alterSize(-tempsize);
		
	}
	else
	{
		alterSize(-amount);
	}

}

//**********************************************
//The members of animal class are described below
//**********************************************

//The following is a constructor that sets size, growthRate, and needThisWeek with the value assigned, and sets eatenThisWeek to 0
animal::animal(double initSize, double initRate, double initNeed): organism(initSize, initRate)
{

	needThisWeek= initNeed;
	eatenThisWeek= 0.0;

}

//The following reassigns needsThisWeek to the value passed in
void animal::assignNeed(double newNeed)
{
	needThisWeek= newNeed;
	cout<< needThisWeek<< endl;

}

//The following increments eatenThisWeek by amount
void animal::eat(double amount)
{
	eatenThisWeek+= amount;

}

/*The following increments the size by growthRate if eatenThisWeek is greater than or equal to needThis Week,
 otherwise set size, growthRate, and eatenThisWeek to 0*/
void animal::simulateWeek()
{
	double tempgrowthRate= getRate();
	

	if(eatenThisWeek >= needThisWeek)
	{
		alterSize(tempgrowthRate);
		eatenThisWeek=0.0;
	}
	else
	{

		death();
		eatenThisWeek= 0.0;
		
	}

}

/*The following returns 0 if eatenThisWeek is greater than or equal to needThisWeek,
 otherwise it returns the difference between needThisWeek and eatenThisWeek*/ 
double animal::stillNeed() const
{
	double difference;

	if( eatenThisWeek >= needThisWeek)
	{
		difference=0;
	}
	else if( eatenThisWeek < needThisWeek)
	{
		difference= needThisWeek - eatenThisWeek;
	}

	return difference;

}

//The following returns needThisWeek
double animal::totalNeed() const
{
	return needThisWeek;

}

//*************************************************
//The members of herbivore class are decribed below
//*************************************************

const double herbivore::PORTION =0.5;//this constant regulates how big of a portion of the plant object it will consume
const double herbivore::MAX_FRACTION = 0.1;// this regulates how big of a portion the herbivore can consume in one feeding. When nibble is called

//The following is a constructor that sets size, growthRate, needThisWeek with the values passed in and sets eatenThisWeek to 0
herbivore::herbivore(double initSize, double initRate, double initNeed): animal(initSize,initRate, initNeed)
{


}

//The following is a function that consumes a portion of a plant object
void herbivore::nibble(plant& meal)
{
	double amount= PORTION * meal.getSize();
	double sneed= stillNeed();

	if( amount > MAX_FRACTION * totalNeed())
	{

		amount= MAX_FRACTION * totalNeed();
	}

	if ( amount > sneed)
	{
		amount= sneed;
	}



	eat(amount);
	meal.nibbledOn(amount);

}