/**
* This class provides prototype for grouping properties
**/
#include <stdlib.h>
#include <stdio.h>

class Property;
class Group
{
	private:
		// The current size of the group
		int size;
		// The maximum size of the group
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

		/**
		* Adds a property to the group 
		* @param ptr - a pointer to the property
		**/
		void add(Property* ptr);
		
		/**
		* Returns the current size of the group
		* @return - the current size
		**/
		int getSize()
		{
			return size;
		}
		
		/**
		* Returns the maximum size of the group
		* @return - the maximum size
		**/
		int getCapacity()
		{
			return capacity;
		}

		/**
		* Returns the property of a group
		* @param index - the index of the desired property
		* @return - a pointer to the desired property
		**/
		Property* getProperty(int index)
		{
			return arr[index];
		}

		

};
