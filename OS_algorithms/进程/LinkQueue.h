#include<iostream>
using namespace std;
template <class T>
struct Node
{
	T data;
	Node<T> *next;
};

template <class T>
class LinkQueue
{public:
	LinkQueue();
	~LinkQueue();
	void EnQueue(T m);
	T DeQueue();    //将队头元素出队
	T GetQueue();   //取链队列的队头元素
	void SetNullQueue();
	bool Empty();
private:
	Node<T> *front, *rear;
};
