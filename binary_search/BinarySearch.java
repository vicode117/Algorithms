
public class BinarySearch
{

    public static int rank(int key, int[] myList)
    {
        int low = 0;
        int high = myList.length -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int guess = myList[mid];

            if (guess == key)
                return mid;
            else if (guess >key)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return -1;
    }


    public static void main(String[] args)
    {
        int[] myList = {1, 2, 3, 4, 5, 22, 44, 55};

        System.out.println("guess = " + rank(4, myList));

    }

}
