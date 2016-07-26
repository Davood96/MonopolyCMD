/**
* This class simulates a die
**/
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <cmath>

using namespace std;

class Die
{

	private:
		std::random_device r;
		std::default_random_engine* generator;
		std::uniform_int_distribution<int>* distribution;

	public:
		Die(){distribution = new std::uniform_int_distribution<int>(1, 6);}
		~Die(){}
	
	/**
	* Simulates a die roll
	* @return - the result of the die roll
	**/
	int roll()
	{	
		//Increase 'randomness'
		generator = new std::default_random_engine(r());

		int one;
		one = (*distribution)(*generator); 
		delete generator;
		return one;
	}


};
