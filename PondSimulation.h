#include <iostream>
#include <cmath>

using namespace std;


class organism
{
	public :
	organism ( double = 1, double = 0);//The following is a constructor that sets growthRate and size with the values passed in
	void simulateWeek ();//The following increments the size by growthRate
	void assignRate ( double );//The following assigns growthRate with the value passed in
	void alterSize ( double );//The following increments the size by the amount passed in
	void death ();//The following sets growthRate and size to 0
	double getSize () const ;//The following returns size
	double getRate () const ;//The following returns growthRate
	bool isAlive () const ;//The following returns true if size is larger than 0, otherwise it returns false
	private :
	double growthRate;//dentoes the growth rate of the organsim
	double size;// dentoes the size of the organsim
};


class plant : public organism
{
	public :
	plant ( double = 1 , double = 0);//The following is a constructor that sets growthRate and size with the value passed in
	void nibbledOn ( double );//The following decreases the size by amount, if the amount is larger than the size, then it set the size to 0
};


class animal : public organism
{
	public :
	animal ( double = 1 , double = 0 , double = 0);//The following is a constructor that sets size, growthRate, and needThisWeek with the value assigned, and sets eatenThisWeek to 0
	void assignNeed ( double );//The following reassigns needsThisWeek to the value passed in
	void eat ( double );//The following increments eatenThisWeek by amount
	void simulateWeek ();/*The following increments the size by growthRate if eatenThisWeek is greater than or equal to needThis Week,
 otherwise set size, growthRate, and eatenThisWeek to 0*/
	double stillNeed () const ;/*The following returns 0 if eatenThisWeek is greater than or equal to needThisWeek,
 otherwise it returns the difference between needThisWeek and eatenThisWeek*/ 
	double totalNeed () const ;//The following returns needThisWeek
	private :
	double needThisWeek;//denotes the amount of food that needs to be consumed in a week
	double eatenThisWeek;// denotes the amount of food that was eaten in the current week
};


class herbivore : public animal
{
	public :
	static const double PORTION ;//this constant regulates how big of a portion of the plant object it will consume
	static const double MAX_FRACTION ;// this regulates how big of a portion the herbivore can consume in one feeding. When nibble is called
	herbivore ( double = 1 , double = 0 , double = 0);//The following is a constructor that sets size, growthRate, needThisWeek with the values passed in and sets eatenThisWeek to 0
	void nibble ( plant &);//The following is a function that consumes a portion of aplant object
};