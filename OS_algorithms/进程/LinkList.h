#include<iostream>
using namespace std;

template <class T>
struct Node1
{
	T data;
	Node1<T>* next;
};

template <class T>
class LinkList
{ public:
	LinkList();
//	LinkList(T a[], int n);
//	LinkList(int n, T a[]);
	~LinkList();
	int GetLength();
	T Get(int i);
	void Set(int i, T x);
	int Locate(T x);
	void Insert(int i,T x);
	T Delete(int i);
	Node1<T> GetFirst();
	void SetFirst(Node1<T> *p){ first=p; }
	void PrintLinkList();
  private:
	Node1<T> *first;
};
