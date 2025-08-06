

import java.util.*;

public class MergeSortExample {

    public static void mergeSort(ArrayList<Integer> arr, int low, int mid, int high) {
        ArrayList<Integer> temp = new ArrayList<>();
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr.get(left) <= arr.get(right)) {
                temp.add(arr.get(left));
                left++;
            } else {
                temp.add(arr.get(right));
                right++;
            }
        }

        while (left <= mid) {
            temp.add(arr.get(left));
            left++;
        }

        while (right <= high) {
            temp.add(arr.get(right));
            right++;
        }

        for (int i = low; i <= high; i++) {
            arr.set(i, temp.get(i - low));
        }
    }

    public static void merge(ArrayList<Integer> arr, int low, int high) {
        if (low >= high)
            return;

        int mid = (low + high) / 2;
        merge(arr, low, mid);
        merge(arr, mid + 1, high);
        mergeSort(arr, low, mid, high);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the size of the array: ");
        int n = sc.nextInt();

        ArrayList<Integer> arr = new ArrayList<>(n);
        System.out.println("Enter the elements of the array: ");
        for (int i = 0; i < n; i++) {
            arr.add(sc.nextInt());
        }

        merge(arr, 0, n - 1);

        System.out.print("\nArray after sorting: ");
        for (int i = 0; i < n; i++) {
            System.out.print(arr.get(i) + " ");
        }
        System.out.println();

        sc.close();
    }
}
