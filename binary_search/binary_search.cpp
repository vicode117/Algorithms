#include <iostream>
using namespace std;

int binarySearch(int myList[], int len, int key)
{
    int low = 0;
    int high = len-1;

    while (low <= high) {
       int mid = (high + low) / 2;
       int guess = myList[mid];

       if (guess == key)
           return mid;
       else if (guess > key)
           high = mid -1;
       else
           low = mid + 1;
    }

    return -1;
}

int main()
{

    int myList[8] = {1, 2, 3, 4, 5, 22, 44, 55};

    cout<<"guess = "<<binarySearch(myList, 8, 22)<<endl;

    return 0;
}
