#include<iostream>
#include"LinkList.cpp"
#include"LinkQueue.cpp"

using namespace std;

struct Process1
{
	int CPU_time;
	int Priority;
	int num;
};

struct Process2
{
	int TimeC;
	int Time;
	int CPU_time;
	int num;
};


LinkList<Process1> P1;
LinkQueue<Process2> P2;

void CreateProcess1(int n, Process1* p)
{
	srand((unsigned)time(0));
	//Process1 p[n];

	for(int i=0;i<n;i++) {
		p[i].CPU_time=rand()%20+1;
		p[i].Priority=rand()%30+1;
		p[i].num=i+1;
	}
	for(int i=0;i<n;i++)
		cout<<"进程"<<p[i].num<<":\t所需CPU时间"<<p[i].CPU_time
	<<"\t优先权"<<p[i].Priority<<endl;



}

void CreateProcess2(int n, Process2* p)
{
	srand((unsigned)time(0));
	//Process1 p[n];

	for(int i=0;i<n;i++) {
		p[i].CPU_time=0;
		p[i].TimeC=rand()%5+1;
		p[i].Time=p[i].TimeC+rand()%30+1;
		p[i].num=i+1;
	}
	for(int i=0;i<n;i++)
		cout<<"进程"<<p[i].num<<":\t所需CPU时间"<<p[i].Time
	<<"\t轮转时间片数"<<p[i].TimeC<<endl;
}


void InsertQueue1(int n, Process1* p)
{
	CreateProcess1(n,p);
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
			if(p[j].Priority>p[j+1].Priority)
			{
				Process1 t;
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
			}

		P1.Insert(i+1,p[n-i-1]);
	}
	P1.Insert(n,p[0]);
	
}

void InsertQueue2(int n, Process2* p)
{
	CreateProcess2(n,p);
	for(int i=0;i<n;i++)
		P2.EnQueue(p[i]);
}

void PCB1(int n, Process1* p)
{
	InsertQueue1(n,p);
	Process1 temp;
	cout<<"\n开始运行\n"<<endl;
	while(n>0) {	
		temp=P1.Get(1);
		P1.Delete(1);
		if(temp.Priority>=3)
			temp.Priority-=3;
		else
			temp.Priority=0;
		temp.CPU_time--;
		cout<<"进程"<<temp.num<<":\t当前CPU时间"<<temp.CPU_time
			<<"\t当前优先权"<<temp.Priority<<endl;

		if(temp.CPU_time>0) {
			bool a=0;
			for(int i=1;i<n;i++)	
				if(P1.Get(i).Priority<temp.Priority)
				{
					P1.Insert(i,temp);
					a=1;
					break;
				}
			if(a==0)
				P1.Insert(n,temp);	
							
		}
		else {
			cout<<"进程"<<temp.num<<"运行完毕"<<endl;		
			n--;		
		}
	}
	cout<<"全部运行完毕"<<endl;
}

void PCB2(int n, Process2* p)
{
	InsertQueue2(n,p);
	Process2 temp;
	cout<<"\n开始运行\n"<<endl;

	while(n>0) {
		temp=P2.DeQueue();
		if(temp.Time>temp.TimeC)
		{
			temp.Time-=temp.TimeC;
			temp.CPU_time+=temp.TimeC;
			cout<<"进程"<<temp.num<<":\t目前还需时间"<<temp.Time
				<<"\t已占用CPU时间"<<temp.CPU_time<<endl;
			P2.EnQueue(temp);
		}
		else
		{
			temp.CPU_time+=temp.Time;
			temp.Time=0;
			cout<<"进程"<<temp.num<<"远行完毕"<<"\t运行总时间为"
				<<temp.CPU_time<<endl;
			n--;
		}		
	}
	cout<<"全部运行完毕"<<endl;


}

int main()
{
	try {
	int n,method;
	cout<<"Please enter the number of Process,4~8"<<endl;
	cin>>n;
	cout<<"Please select the scheduling algorithm"	
		<<"\nEnter 1:Priority Algorithm\t Enter 2:Rotation Algorithm"<<endl;
	cin>>method;
	if(method==1) {
		Process1 p[n];
		PCB1(n,p);
	}
	else if(method==2) {
		Process2 p[n];
		PCB2(n,p);

	}
	else 
		cout<<"输入有误"<<endl;
			
		
	}
	catch(const char* wrong)
		{ cout<<wrong<<endl; }
	return 0;
}



/*
1.产生的各种随机数的取值范围加以限制，如所需的 CPU 时间限制在 1~20 之间。
2.进程数 n 不要太大通常取 4~8 个
3.使用动态数据结构
4.独立编程
5.二种调度算法
6.若有可能请在图形方式下，将 PCB 的调度用图形成动画显示。
 */

