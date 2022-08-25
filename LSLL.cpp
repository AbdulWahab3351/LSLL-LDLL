#include "LSLL.h"
#include<iostream>
using namespace std;

template<typename T>
LSLL<T>::LSLL()
{
	head = nullptr;
}
template<typename T>
void LSLL<T>::insertAtHead(T h)
{
	Node<T>* temp = new Node<T>(h);
	temp->next = head;
	head = temp;
}

template<typename T>
LSLL<T>::LSLL(const LSLL<T>& ref)
{
	if (!ref.head)
	{
		head = nullptr;
		return;
	}
	Node<T>* refPtr = ref.head;
	Node<T>* objPtr = new Node<T>(refPtr->info);
	head = objPtr;
	while (refPtr->next)
	{
		refPtr = refPtr->next;
		objPtr->next = new Node<T>(refPtr->info);
		objPtr = objPtr->next;
	}
}

template<typename T>
LSLL<T>& LSLL<T>::operator=(const LSLL<T>& ref) 
{
	if (&ref == this)
		return *this;
	this->~LSLL<T>();
	if (!ref.head)
		return *this;
	Node<T>* refPtr = ref.head;
	Node<T>* objPtr = new Node<T>(refPtr->info);
	head = objPtr;
	while (refPtr->next)
	{
		refPtr = refPtr->next;
		objPtr->next = new Node<T>(refPtr->info);
		objPtr = objPtr->next;
	}
	return *this;
}
template <typename T>
LSLL<T>::~LSLL()
{
	if (!head)
		return;
	Node<T>* temp = head;
	Node<T>* traverse;
	while (temp)
	{
		traverse = temp->next;
		delete temp;
		temp = traverse;
	}
	head = nullptr;
}
template <typename T>
void LSLL<T>::insertAtTail(T t)
{
	if (!head)
	{
		insertAtHead(t);
		return;
	}
	Node<T>* traverse = head;
	while (traverse->next)
		traverse = traverse->next;
	traverse->next = new Node<T>(t);
}
template<typename T>
void LSLL<T>::removeAtHead()
{
	if (!head)
		return;
	Node<T>* temp = head->next;
	delete head;
	head = temp;
}
template<typename T>
void LSLL<T>::removeAtTail()
{
	if (!head)
		return;
	if(!(head->next))
	{
		removeAtHead();	
		return;
	}
	Node<T>* traverse = head;
	while (traverse->next->next)
		traverse = traverse->next;
	delete traverse->next;
	traverse->next = nullptr;
}
template<typename T>
void LSLL<T>:: remove(T obj)
{
	if (!head)
		return;
	if (head->info == obj)
	{
		removeAtHead();
		return;
	}
	Node<T>* traverse = head->next;
	Node<T>* prev = head;
	while (traverse)
	{
		if (traverse->info == obj)
		{
			prev->next = traverse->next;
			delete traverse;
			return;
		}
		prev = traverse;
		traverse = traverse->next;
	}
}
template<typename T>
void LSLL<T> :: insertAfter(T key, T val)
{
	if (!head)
		return;
	Node<T>* traverse = head;
	while (traverse)
	{
		if (traverse->info == key)
		{
			Node<T>* temp = new Node<T>(val);
			temp->next = traverse->next;
			traverse->next = temp;
			return;
		}
		traverse = traverse->next;
	}
}
template<typename T>
void LSLL<T> ::insertBefore(T key, T val)
{
	if (!head)
		return;
	if (head->info == key)
	{
		insertAtHead(val);
		return;
	}
	Node<T>* traverse = head->next;
	Node<T>* prev = head;
	while (traverse)
	{
		if (traverse->info == key)
		{
			Node<T>* temp = new Node<T>(val);
			temp->next = traverse;
			prev->next = temp;
			return;
		}
		prev = traverse;
		traverse = traverse->next;
	}
}
template<typename T>
void LSLL<T> :: removeAfter(T key)
{
	if (!head || !head->next)
		return;
	Node<T>* traverse = head;
	while (traverse)
	{
		if ((traverse->info == key) && traverse->next)
		{
			Node<T>* temp = traverse->next->next;
			delete traverse->next;
			traverse->next = temp;
			return;
		}
		traverse = traverse->next;
	}
}
template<typename T>
void LSLL<T> :: removeBefore(T key)
{
	if (!head || head->info==key)
		return;
	if (head->next && head->next->info == key)
	{
		Node<T>* temp = head->next;
		delete head;
		head = temp;
		return;
	}
	Node<T>* traverse = head->next->next;
	Node<T>* prevOfPrev = head;
	while (traverse)
	{
		if (traverse->info == key)
		{
			delete prevOfPrev->next;
			prevOfPrev->next = traverse;
			return;
		}
		prevOfPrev = prevOfPrev->next;
		traverse = traverse->next;
	}
}
template<typename T>
void LSLL<T> ::display()
{
	Node<T>* temp = head;
	while (temp)
	{
		cout << temp->info << " ";
		temp = temp->next;
	}
	cout << '\n';
}
//template <typename T>
//T& LSLL<T>::Iterator<T>::operator*()
//{
//	return cur->info;
//}
template<typename T>
LSLL<T>::Iterator<T> LSLL<T>:: begin()
{
	return  Iterator<T>(head);
}
template<typename T>
LSLL<T>::Iterator<T> LSLL<T>::end()
{
	return Iterator<T>(nullptr);
}