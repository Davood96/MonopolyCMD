#ifndef Deck_H
#define Deck_H
#include <stdlib.h>
#include <stdio.h>
#include <random>
#include <cmath>
#include "DList.h"
#define CARDS 4

class Player;
using namespace std;

template <typename T> class Deck : public DList<T>
{
	private:
		std::random_device r;
		std::default_random_engine* generator;
		std::uniform_int_distribution<int>* distribution;

	public:
		Deck<T>() : DList<T>()
		{
			distribution = new std::uniform_int_distribution<int>(1, CARDS - 1);
			generator = new std::default_random_engine(r());
		}

		~Deck<T>(){}


		int generate()
		{
			return (*distribution)(*generator);
		}

		virtual int drawCard(Player* plyr) = 0;

};
#endif
