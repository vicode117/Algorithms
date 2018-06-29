#include<iostream>
#include"stdlib.h"
#include"time.h"
using namespace std;

struct Process
{
		int trackNum;
		int distance;
};

int n;					//欲访问的磁道总数

Process first;	//当前磁头指向的磁道号

void CreateProcess(Process* p)
{
	srand((unsigned)time(0));

	for(int i=0;i<n;i++)
	{
		p[i].trackNum=rand()%199;
	}
	cout<<"欲访问磁道号如下"<<endl;
	for(int i=0;i<n;i++)
		cout<<p[i].trackNum<<"\t";
	cout<<endl;
}

void SCAN(Process* p)
{
	int temp[n+1],dis[n];
	for(int i=0;i<n+1;i++)
	{
		temp[i]=p[i].trackNum;
		dis[n]=p[i].distance=0;

	}		temp[n]=first.trackNum;
	for(int i=0;i<n;i++)				//用冒泡排序法进行排序 
        for(int j=0;j<n-i;j++)  
            if(temp[j]>temp[j+1])  
            {  
                int t=temp[j];  
                temp[j]=temp[j+1];  
                temp[j+1]=t;  
            }
	int begin;
	for(int i=0;i<n+1;i++)		//找到排序后磁头所在磁盘号的位置		
		while(temp[i]==first.trackNum)
		{
			begin=i;	break;
		}
	cout<<"磁道号访问顺序如下"<<endl;
	for(int i=begin;i<n+1;i++)
		cout<<temp[i]<<"\t";	
	for(int i=begin-1;i>-1;i--)
		cout<<temp[i]<<"\t";
	cout<<endl;
	cout<<"寻道长度";
	for(int i=begin;i<n;i++)
		dis[i-begin]=temp[i+1]-temp[i];
	dis[n-begin]=temp[n]-temp[begin-1];
	for(int i=begin-1;i>0;i--)
		dis[n-i]=temp[i]-temp[i-1];
	for(int i=0;i<n;i++)
		cout<<dis[i]<<"\t";
	cout<<endl;
	cout<<"平均寻道长度为"
			<<(float)(temp[n]-temp[0]+temp[n]-first.trackNum)/n<<endl;	
}


int main()
{	
loop:
	cout<<"请输入欲访问的磁道总数(5~30)和当前磁头指向的磁道号(0~199)"<<endl;
	cin>>n>>first.trackNum;
	Process p[n];
	CreateProcess(p);
	SCAN(p);
	cout<<"(输入Y/y重新测试算法，输入其它任意字符退出)"<<endl;
	char s;	cin>>s;
	if(s=='Y'||s=='y')
		goto	loop;
	return 0;
}
