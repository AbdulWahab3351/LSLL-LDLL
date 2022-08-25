#include "LDLL.h"
#include<iostream>
using namespace std;
template<typename T>

LDLL<T>::LDLL()
{
	head = nullptr;
}
template <typename T>
LDLL<T>::LDLL(const LDLL<T>& ref)
{
	if (!ref.head)
	{
		head = nullptr;
		return;
	}
	DNode<T>* refPtr = ref.head;
	DNode<T>* objPtr = new DNode<T>(refPtr->info);
	head = objPtr;
	while (refPtr->next)
	{
		refPtr = refPtr->next;
		objPtr->next = new DNode<T>(refPtr->info);
		objPtr->next->prev = objPtr;
		objPtr = objPtr->next;
	}
}
template<typename T>
LDLL<T>& LDLL<T> :: operator=(const LDLL<T>& ref)
{
	if (&ref == this)
		return *this;
	this->~LDLL<T>();
	if (!ref.head)
		return *this;
	DNode<T>* refPtr = ref.head;
	DNode<T>* objPtr = new DNode<T>(refPtr->info);
	head = objPtr;
	while (refPtr->next)
	{
		refPtr = refPtr->next;
		objPtr->next = new DNode<T>(refPtr->info);
		objPtr->next->prev = objPtr;
		objPtr = objPtr->next;
	}
	return *this;
}
template<typename T>
LDLL<T> :: ~LDLL()
{
	if (!head)
		return;
	DNode<T>* temp = head;
	DNode<T>* traverse;
	while (temp)
	{
		traverse = temp->next;
		delete temp;
		temp = traverse;
	}
	head = nullptr;
}
template<typename T>
void LDLL<T> :: insertAtHead(T h)
{
	if(!head)
	{
		head = new DNode<T>(h);
		return;
	}
	DNode<T>* temp = new DNode<T>(h);
	temp->next = head;
	head->prev = temp;
	head = temp;
}
template<typename T>
void LDLL<T>::insertAtTail(T t)
{
	if (!head)
	{
		head = new DNode<T>(t);
		return;
	}
	DNode<T>* traverse = head;
	while (traverse->next)
		traverse = traverse->next;
	traverse->next = new DNode<T>(t);
	traverse->next->prev = traverse;
}
template<typename T>
void LDLL<T>:: insertAfter(T key, T val)
{
	if (!head)
		return;
	DNode<T>* traverse = head;
	while (traverse)
	{
		if (traverse->info == key)
		{
			DNode<T>* temp = new DNode<T>(val);
			temp->next = traverse->next;
			temp->prev = traverse;
			if (temp->next)
				temp->next->prev = temp;
			traverse->next = temp;
			return;
		}
		traverse = traverse->next;
	}
}
template<typename T>
void LDLL<T>:: insertBefore(T key, T val)
{
	if (!head)
		return;
	if (head->info == key)
	{
		DNode<T>* temp = new DNode<T>(val);
		temp->next = head;
		head->prev = temp;
		head = temp;
		return;
	}
	DNode<T>* traverse = head->next;
	while (traverse)
	{
		if (traverse->info == key)
		{
			DNode<T>* temp = new DNode<T>(val);
			temp->next = traverse;
			temp->prev = traverse->prev;
			traverse->prev = temp;
			temp->prev->next = temp;
			return;
		}
		traverse = traverse->next;
	}
}
template<typename T>
void LDLL<T>:: removeAtHead()
{
	if (!head)
		return;
	if (!head->next)
	{
		delete head;
		head = nullptr;
		return;
	}
	DNode<T>* temp = head->next;
	delete head;
	head = temp;
	head->prev = nullptr;
}
template<typename T>
void LDLL<T>:: removeAtTail()
{
	if (!head)
		return;
	if (!(head->next))
	{
		delete head;
		head = nullptr;
		return;
	}
	DNode<T>* traverse = head->next;
	while (traverse)
	{
		if (!(traverse->next))
		{
			traverse->prev->next = nullptr;
			delete traverse;
			return;
		}
		traverse = traverse->next;
	}
}
template<typename T>
void LDLL<T> ::display()
{
	DNode<T>* temp = head;
	while (temp)
	{
		cout << temp->info << " ";
		temp = temp->next;
	}
	cout << '\n';
}
template<typename T>
void LDLL<T>:: displayInReverseOrder()
{
	if (!head)
		return;
	DNode<T>* traverse = head;
	while (traverse->next)
		traverse = traverse->next;
	while (traverse)
	{
		cout << traverse->info << " ";
		traverse = traverse->prev;
	}
	cout << '\n';
}
template<typename T>
void LDLL<T>:: removeAfter(T key)
{
	if (!head)
		return;
	DNode<T>* traverse = head;
	while (traverse)
	{
		if (traverse->info == key && traverse->next)
		{
			DNode<T>* temp = traverse->next->next;
			delete traverse->next;
			traverse->next = temp;
			if(temp)
				temp->prev = traverse;
			return;
		}
		traverse = traverse->next;
	}
}
template<typename T>
void LDLL<T>::removeBefore(T key)
{
	if (!head || head->info == key)
		return;
	if (head->next && head->next->info == key)
	{
		removeAtHead();
		return;
	}
	DNode<T>* traverse = head->next->next;
	while (traverse)
	{
		if (traverse->info == key)
		{
			DNode<T>* temp = traverse->prev->prev;
			temp->next = traverse;
			delete traverse->prev;
			traverse->prev = temp;
			return;
		}
		traverse = traverse->next;
	}
}
template<typename T>
void LDLL<T>:: remove(T obj)
{
	if (!head)
		return;
	if (head->info == obj)
	{
		removeAtHead();
		return;
	}
	DNode<T>* traverse = head;
	while (traverse->next)
	{
		if (traverse->next->info == obj)
		{
			DNode<T>* next = traverse->next->next;
			delete traverse->next;
			traverse->next = next;
			if(next)
				next->prev = traverse;
			return;
		}
		traverse = traverse->next;
	}
}
template<typename T>
LDLL<T>::Iterator<T> LDLL<T>::begin()
{
	return  Iterator<T>(head);
}
template<typename T>
LDLL<T>::Iterator<T> LDLL<T>::rbegin()
{
	if (!head)
		Iterator<T>(nullptr);
	DNode<T>* ptr = head;
	while (ptr->next)
		ptr = ptr->next;
	return Iterator<T>(ptr);
}
template<typename T>
LDLL<T>::Iterator<T> LDLL<T>::end()
{
	return Iterator<T>(nullptr);
}
template<typename T>
LDLL<T>::Iterator<T> LDLL<T>::rend()
{
	return Iterator<T>(nullptr);
}







