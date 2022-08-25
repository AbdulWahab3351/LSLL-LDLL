#include<iostream>
#include<vector>
using namespace std;
#include"LSLL.h"
#include"LDLL.h"

int main()
{
	LDLL<int> a;
	a.insertAtTail(1);
	a.insertAtTail(2);
	a.insertAtTail(3);
	a.insertAtTail(4);
	a.insertAtTail(5);
	a.insertAtTail(6);
	a.display();
	for (auto obj : a)
	{
		cout << obj << " ";
		obj = 7;
	}
	cout << endl;
	cout << endl;
	LDLL<int>::Iterator<int> start = a.rbegin();
	LDLL<int>::Iterator<int> end = a.rend();
	while (start != end)
	{
		cout << *start << " ";
		*start = 6;
		start--;
	}
	cout << '\n';
	
	return 0;
}