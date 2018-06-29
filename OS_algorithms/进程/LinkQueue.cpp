#include<iostream>
#include"LinkQueue.h"
using namespace std;

template <class T>
LinkQueue<T>::LinkQueue()
{
	Node <T> *s;
	s=new Node<T>;
	s->next=NULL;
	front=rear=s;
}

template <class T>
LinkQueue<T>::~LinkQueue()
{
	while ( front )
	{
		Node <T> *p;
		p=front->next;
		delete front;
		front=p;
	}

}

template <class T>
void LinkQueue<T>::EnQueue(T x)
{
	Node<T> *s;
	s=new Node<T>;
	s->data=x;
	s->next=NULL;
	rear->next=s;
	rear=s;
}

template <class T>
T LinkQueue<T>::DeQueue()
{
	Node <T> *p; T x;
	if(rear==front)
		throw "下溢";
	p=front->next;
	x=p->data;
	front->next=p->next;
	if(p->next==NULL)
		rear=front;
	delete p;
	return x;
}

template <class T>
T LinkQueue<T>::GetQueue()
{
	if(front!=rear)
		return front->next->data;
	else throw "下溢";

}

template <class T>
bool LinkQueue<T>::Empty()
{
	if(front==rear)
		return 1;
	else
		return 0;
}

template <class T>
void LinkQueue<T>::SetNullQueue()
{ rear=front;}

/*
int main()
{

	return 0;	
}
*/








