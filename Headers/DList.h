/**
* This file provides a template for a doublely-linked list
**/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "DNode.h"

using namespace std;
template <class T> class DList
{
	private:
		DNode<T>* head;
		DNode<T>* tail;
		int size;

	public:
		DList<T>();

		~DList<T>(){}

		void insertAtTail(DNode<T>* new_node);
		void insertAtHead(DNode<T>* new_node);
		DNode<T>* removeAtHead();
		void printList();
		DNode<T>* swap(DNode<T>* first, DNode<T>* second);

		DNode<T>* getFirst();
		DNode<T>* getLast();
		

};

template <class T> DList<T>::DList()
{
	head = new DNode<T>();
	tail = new DNode<T>();
	head->setNext(tail);
	head->setPrev(NULL);
	tail->setNext(NULL);
	tail->setPrev(head);
}

template <class T> DNode<T>* DList<T>::getFirst()
{
	return head->getNext();
}

template <class T> DNode<T>* DList<T>::getLast()
{
	return tail->getPrev();
}

template <class T> DNode<T>* DList<T>::swap(DNode<T>* first,DNode<T>* second)
{
	DNode<T>* left = first->getPrev();
	DNode<T>* right = second->getNext();

	left->setNext(second);
	second->setPrev(left);
	
	right->setPrev(first);
	first->setNext(right);

	second->setNext(first);
	first->setPrev(second);

	return first;
}

template <class T> void DList<T>::insertAtTail(DNode<T>* new_node)
{
	DNode<T>* curr_last = tail->getPrev();
	new_node->setNext(tail);
	tail->setPrev(new_node);
	curr_last->setNext(new_node);
	new_node->setPrev(curr_last);
	size++;
}

template <class T> void DList<T>::insertAtHead(DNode<T>* new_node)
{
	DNode<T>* curr_first = head->getNext();
	new_node->setPrev(head);
	head->setNext(new_node);
	curr_first->setPrev(new_node);
	new_node->setNext(curr_first);
	size++;
}

template <class T> DNode<T>* DList<T>::removeAtHead()
{
	DNode<T>* removed = head->getNext();
	head->setNext(removed->getNext());
	(removed->getNext())->setPrev(head);
	removed->setNext(NULL);
	removed->setPrev(NULL);
	return removed;
}

template <class T> void DList<T>::printList()
{
	DNode<T>* curr = head->getNext();
	while(curr != tail)
	{
		std::cout << curr->getData() << " ";
		curr = curr->getNext();
	}
	printf("\n");

}
