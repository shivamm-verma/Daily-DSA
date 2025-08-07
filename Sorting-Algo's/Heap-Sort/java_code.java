import java.util.ArrayList;
import java.util.Scanner;

public class HeapSortExample {

    public static void heapify(ArrayList<Integer> arr, int n, int i) {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left <= n && arr.get(largest) < arr.get(left)) {
            largest = left;
        }
        if (right <= n && arr.get(largest) < arr.get(right)) {
            largest = right;
        }

        if (largest != i) {
            int temp = arr.get(i);
            arr.set(i, arr.get(largest));
            arr.set(largest, temp);
            heapify(arr, n, largest);
        }
    }

    public static void heapSort(ArrayList<Integer> arr, int n) {
        int size = n;
        while (size > 1) {
            int temp = arr.get(size);
            arr.set(size, arr.get(1));
            arr.set(1, temp);

            size--;
            heapify(arr, size, 1);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(0); // dummy index for 1-based indexing

        for (int i = 0; i < n; i++) {
            arr.add(sc.nextInt());
        }

        for (int i = n / 2; i > 0; i--) {
            heapify(arr, n, i);
        }

        System.out.print("Printing the array after heapify :: ");
        for (int i = 1; i <= n; i++) {
            System.out.print(arr.get(i) + " ");
        }

        heapSort(arr, n);

        System.out.println();
        System.out.print("Printing the sorted array :: ");
        for (int i = 1; i <= n; i++) {
            System.out.print(arr.get(i) + " ");
        }

        sc.close();
    }
}
