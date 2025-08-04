import java.util.*;

public class Solution {

    static void mysort(int[] arr) {
        int low = 0;
        int mid = 0;
        int high = arr.length - 1;

        // Iterate until all elements are processed
        while (mid <= high) {
            switch (arr[mid]) {
                case 0:
                    // Swap 0 to the front
                    int temp0 = arr[low];
                    arr[low++] = arr[mid];
                    arr[mid++] = temp0;
                    break;

                case 1:
                    // Leave 1 in the middle
                    mid++;
                    break;

                case 2:
                    // Swap 2 to the end
                    int temp2 = arr[mid];
                    arr[mid] = arr[high];
                    arr[high--] = temp2;
                    break;
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = {0, 1, 2, 0, 1, 2};

        // Sort the array in-place using Dutch Flag Algorithm
        mysortt(arr);

        // Print the sorted array
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
