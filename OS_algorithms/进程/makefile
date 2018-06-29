process: Process.o LinkList.o LinkQueue.o
	g++ -o process Process.o LinkList.o LinkQueue.o
Process.o: Process.cpp LinkList.cpp LinkQueue.cpp 
	g++ -c Process.cpp -o Process.o
LinkList.o: LinkList.cpp LinkList.h
	g++ -c LinkList.cpp -o LinkList.o
LinkQueue.o: LinkQueue.cpp LinkQueue.h
	g++ -c LinkQueue.cpp -o LinkQueue.o
clear:
	rm *.o
