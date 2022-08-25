#ifndef LDLL_H
#define LDLL_H
#include"DNode.h"
template<typename T>
class LDLL
{
	DNode<T>* head;
public:
	LDLL();
	LDLL(const LDLL<T>& ref);
	LDLL<T>& operator=(const LDLL<T>& ref);
	~LDLL();
	void insertAtHead(T h);
	void insertAtTail(T t);
	void insertAfter(T key, T val);
	void insertBefore(T key, T val);
	void removeAtHead();
	void removeAtTail();
	void removeAfter(T key);
	void removeBefore(T key);
	void remove(T obj);
	void display();
	void displayInReverseOrder();

	template<typename T>
	class Iterator
	{
		friend class LDLL<T>;
		DNode<T>* cur;
		Iterator(DNode<T>* h) :cur(h)
		{ }
	public:
		DNode<T>* operator++()
		{
			cur = cur->next;
			return cur;
		}
		DNode<T>* operator--()
		{
			cur = cur->prev;
			return cur;
		}
		DNode<T>* operator++(int)
		{
			DNode<T>* temp = cur;
			cur = cur->next;
			return temp;
		}
		DNode<T>* operator--(int)
		{
			DNode<T>* temp = cur;
			cur = cur->prev;
			return temp;
		}
		T& operator*()
		{
			return cur->info;
		}
		bool operator!=(Iterator<T> obj)
		{
			return obj.cur != this->cur;
		}
	};

	Iterator<T> begin();
	Iterator<T> rbegin();
	Iterator<T> end();
	Iterator<T> rend();
};


#endif // !LDLL_H

