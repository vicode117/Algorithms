#include<iostream>
#include"LinkList.h"
using namespace std;

template <class T>
LinkList<T>::LinkList()
{
	first=new Node1<T>;
	first->next=NULL;

}

template <class T>
T LinkList<T>::Get(int i)
{
	Node1<T>* p=first->next; 
	int j=1;
	while(p&&j<i) {
		p=p->next;
		j++;
	}
	if(!p)
		throw "位置错误\n";
	else
		return p->data;
}

template <class T>
void LinkList<T>::Insert(int i,T x)
{
	Node1<T> *p=first; int j=0;
	while (p&&j<i-1)
	{
		p=p->next;
		j++;
	}
	if(!p) throw "位置错误\n";
	else {
		Node1<T>* s=new Node1<T>;
		s->data=x;
		s->next=p->next;
		p->next=s;
	}	
}

template <class T>
T LinkList<T>::Delete(int i)
{
	Node1<T> *p=first;
	int j=0;
	while(p&&j<i-1)
	{ p=p->next; j++; }
	if(!p||!p->next) throw "位置\n";
	else{
		Node1<T>* q=p->next;
		T x=q->data;
		p->next=q->next;
		delete q; return x;
	}
}

template <class T>
LinkList<T>::~LinkList()
{
	Node1<T> *p=first;
	while (p)
	{
		Node1<T> *q=p;
		p=p->next;
		delete q;
	}

}

template <class T>
int LinkList<T>::GetLength()
{
	Node1<T> *p=first;
	int j=0;
	while (p)
	{
		p=p->next;
		j++;;
	}
	return j;
}

template <class T>
void LinkList<T>::Set(int i, T x)
{
	Node1<T> *p=first->next;
	int j=1;
	while(p&&j<i) {
		p=p->next;
		j++;
	}
	if(!p)
		throw "位置错误";
	else p->data=x;
}

template <class T>
void LinkList<T>::PrintLinkList()
{
	Node1<T>* p=first->next;
	while(p) 
	{
		cout<<p->next;
		p=p->next;
	
	}
	
}

template <class T>
Node1<T> LinkList<T>::GetFirst()
{
	return first;
}

/*
int main()
{
	try {
	
	}
	catch(const char* wrong)
		{ cout<<wrong; }
	

	return 0;
}
*/






