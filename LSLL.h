#ifndef LSLL_H
#define LSLL_H
#include"Node.h"

template<typename T>
class LSLL
{
	Node<T>* head;
public:
	LSLL();
	void insertAtHead(T h);
	void insertAtTail(T t);
	void insertAfter(T key, T val);
	void insertBefore(T key, T val);
	void removeAtHead();
	void removeAtTail();
	void removeAfter(T key);
	void removeBefore(T key);
	void remove(T obj);
	~LSLL();
	LSLL(const LSLL<T>& ref);
	LSLL<T>& operator=(const LSLL<T>& ref);
	void display();
	
	template<typename T>
	class Iterator
	{
		friend class LSLL<T>;
		Node<T>* cur;
		Iterator(Node<T>* h):cur(h)
		{ }
	public:
		Node<T>* operator++()
		{
			cur = cur->next;
			return cur;
		}
		Node<T>* operator++(int)
		{
			Node<T>* temp = cur;
			cur = cur->next;
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
	Iterator<T> end();
};

#endif // !LSLL_H


