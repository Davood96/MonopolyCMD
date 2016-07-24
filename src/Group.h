#include <stdlib.h>
#include <stdio.h>

class Property;
class Group
{
	private:
		int size;
		int capacity;
		Property** arr ;
		

	public:
		Group(int am)
		{
			capacity = am;
			arr = (Property**) malloc(capacity * sizeof(Property*));
			size = 0;
		}

		~Group(){}

		void add(Property* ptr);

		int getSize()
		{
			return size;
		}

		int getCapacity()
		{
			return capacity;
		}

		Property* getProperty(int index)
		{
			return arr[index];
		}

		

};
