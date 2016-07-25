/**
* This file provides a template for a doublely-linked list node
**/
#ifndef DNode_H
#define DNode_H
template <class T> class DNode
{
	private:
		T data;
		DNode<T>* prev;
		DNode<T>* next;

	public:
		DNode<T>(T input)
		{
			data = input;
		}

		DNode<T>(T input, DNode<T>* previous, DNode<T>* after)
		{
			data = input;
			prev = previous;
			next = after;
		}

		DNode<T>(){}

		~DNode<T>(){}

		T getData()
		{
			return data;
		}
	
		void setNext(DNode<T>* ptr)
		{
			next = ptr;
		}

		void setPrev(DNode<T>* ptr)
		{
			prev = ptr;
		}

		DNode<T>* getNext()
		{
			return next;
		}

		DNode<T>* getPrev()
		{
			return prev;
		}

};
#endif
