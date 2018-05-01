var binarySearch = function(myList, key) {
    var low = 0;
    var high = myList.length - 1;

    while (low <= high) {
        var mid = Math.floor((low+high) / 2);
        var guess = myList[mid];

        if (guess == key) {
            return mid;
        }else if (guess > key) {
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }

    return -1;

};

var myList = [1, 2, 3, 4, 5, 22, 44, 55];

console.log('guess = ' + binarySearch(myList, 55));
    
