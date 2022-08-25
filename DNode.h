#ifndef D_NODE_H
#define D_NODE_H

template<typename T>
class DNode
{
public:
	T info;
	DNode<T>* next;
	DNode<T>* prev;
	DNode();
	DNode(T val);
};

#endif // !D_NODE_H


