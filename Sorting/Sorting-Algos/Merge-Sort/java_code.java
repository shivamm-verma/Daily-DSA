import java.util.*;

public class java_code {

    /*
     * Function to merge two sorted subarrays into one sorted array:
     * - First subarray: arr[low ... mid]
     * - Second subarray: arr[mid+1 ... high]
     */
    public static void merge(int arr[], int low, int mid, int high) {

        int left = low;
        int right = mid + 1;
        ArrayList<Integer> temp = new ArrayList<>();

        // Merge elements in sorted order
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.add(arr[left]);
                left++;
            } else {
                temp.add(arr[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.add(arr[left]);
            left++;
        }

        while (right <= high) {
            temp.add(arr[right]);
            right++;
        }

        for (int i = 0; i < temp.size(); i++) {
            arr[i + low] = temp.get(i);
        }
    }

    /*
     * Recursive function to perform merge sort:
     * - Divides the array into halves
     * - Recursively sorts each half
     * - Merges the sorted halves
     */
    public static void mergeSort(int arr[], int low, int high) {
        if (low >= high) {
            return;
        }

        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        int arr[] = new int[n];
        System.out.print("Enter the elements of array: ");

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        mergeSort(arr, 0, n - 1);

        // Display the sorted array
        System.out.print("Sorted array is: ");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }

        sc.close();
    }
}
