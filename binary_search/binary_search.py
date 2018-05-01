# -*- coding: utf-8 -*-

def binarySearch(myList, key):
    low = 0
    high = len(myList) - 1

    while low <= high :
        mid = round((low + high)/2)
        guess = myList[mid]

        if guess == key :
            return mid
        elif guess > key :
            high = mid -1
        else :
            low = mid + 1

    return None

myList = [1, 2, 3, 4, 5, 22, 44, 55]

print("guess = %d" % binarySearch(myList, 55))


